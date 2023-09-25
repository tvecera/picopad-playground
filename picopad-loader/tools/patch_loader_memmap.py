from os.path import join, isfile
import shutil

Import("env")

env.Replace(PROGNAME="%s" % env.GetProjectOption("name"))

FRAMEWORK_DIR = env.PioPlatform().get_package_dir("framework-arduinopico")
original_file = join(FRAMEWORK_DIR, "lib", "memmap_default.ld")
patched_file = join("patches", "memmap_default_bootloader.ld")

assert isfile(patched_file)

shutil.copy2(patched_file, original_file)
