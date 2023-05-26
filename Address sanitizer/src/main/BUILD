load("@rules_cc//cc:defs.bzl", "cc_binary")


cc_binary(
    name = "main_address_sanitize",
    srcs = ["main_address_sanitize.cc"],
    # Set this variable to the right path for llvm-symbolizer on your machine.
    env =
        {
            # "ASAN_SYMBOLIZER_PATH": "/usr/local/Cellar/llvm/13.0.0_1/bin/llvm-symbolizer"
            "ASAN_OPTIONS": "detect_stack_use_after_return=1",
        },
    deps = [
    ],
)

cc_binary(
    name = "main_undefined_behavior_sanitizer",
    srcs = ["main_undefined_behavior_sanitizer.cc"],
    deps = [
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        "@com_google_absl//absl/flags:usage",
        "@glog",
    ],
)

