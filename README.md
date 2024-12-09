# ppmlib

Simple library for reading/writing PPM images.

## Usage

Within your `MODULE.bazel` add the following lines:

```
bazel_dep(name = "ppmlib")
git_override(
    module_name = "ppmlib",
    remote = "https://github.com/jasonwyatt/ppmlib.git",
    commit = "f1ec86fa5e544bacec50b82b9bee9e906a7f26b9",
)
```

**Note:** Use the latest commmit from github.

Within your `BUILD` file, depend on the library using `@ppmlib//ppmlib` and include it in your C++ files with `#include "ppmlib/ppm.h"`.

See the samples directory for example usage, it's pretty straightforward.