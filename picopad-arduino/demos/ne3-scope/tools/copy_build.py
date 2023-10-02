Import("env")
import os
import shutil

build_profile = env.subst("$PIOENV")

def post_program_action(source, target, env):
    build_dir = env.subst("$BUILD_DIR")
    prog_name = env.get("PROGNAME")

    if build_profile == "custom-loader":
        build_type = "PP2"
    else:
        build_type = "UF2"

    if not os.path.exists(os.path.join("build", build_type)):
        # Create a new directory because it does not exist
        os.makedirs(os.path.join("build", build_type))

    # Removes all files from the build.
    for filename in os.listdir(os.path.join("build", build_type)):
        file_path = os.path.join("build", build_type, filename)
        if os.path.isfile(file_path):
            os.remove(file_path)

    # Copies all files from the assets directory to the build directory.
    if build_profile == "custom-loader":
        for filename in os.listdir("assets"):
            source_path = os.path.join("assets",  filename)
            destination_path = os.path.join("build", build_type, filename)
            if os.path.isfile(source_path):
                shutil.copy2(source_path, destination_path)

    # Copy build to build directory
    if build_profile == "custom-loader":
        source_path = os.path.join(build_dir, f"{prog_name}.bin")
        destination_path = os.path.join("build", build_type, f"{prog_name}.PP2")
    else:
        source_path = os.path.join(build_dir, f"{prog_name}.uf2")
        destination_path = os.path.join("build", build_type, f"{prog_name}.UF2")

    shutil.copy2(source_path, destination_path)


env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", post_program_action)
