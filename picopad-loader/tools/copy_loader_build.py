Import("env")
import os
import shutil

build_profile = env.subst("$PIOENV")

def post_program_action(source, target, env):
    build_dir = env.subst("$BUILD_DIR")
    progname = env.get("PROGNAME")

    if not os.path.exists("build"):
        # Create a new directory because it does not exist
        os.makedirs("build")

    # Removes all files from the build.
    for filename in os.listdir("build"):
        file_path = os.path.join("build", filename)
        if os.path.isfile(file_path):
            os.remove(file_path)

    # Copies all files from the assets directory to the build directory.
    for filename in os.listdir("assets"):
        source_path = os.path.join("assets", filename)
        destination_path = os.path.join("build", filename)
        if os.path.isfile(source_path):
            shutil.copy2(source_path, destination_path)

    # Copy build to build directory
    if build_profile == "custom-bootloader":
        source_path = os.path.join(build_dir, f"{progname}.bin")
        destination_path = os.path.join("build", f"{progname}.PP2")
        shutil.copy2(source_path, destination_path)
    else:
        source_path = os.path.join(build_dir, f"{progname}.uf2")
        destination_path = os.path.join("build", f"{progname}.uf2")
        shutil.copy2(source_path, destination_path)


env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", post_program_action)
