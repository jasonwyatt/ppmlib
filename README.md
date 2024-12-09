# ppmlib

Simple library for reading/writing PPM images.

## Usage

Within your `MODULE.bazel` add the following lines:

```
bazel_dep(name = "ppmlib", dev_dependency = True)
git_override(
    module_name = "ppmlib",
    remote = "https://github.com/jasonwyatt/ppmlib.git",
    commit = "f1ec86fa5e544bacec50b82b9bee9e906a7f26b9",
)
```

**Note:** Use the latest commmit from github.