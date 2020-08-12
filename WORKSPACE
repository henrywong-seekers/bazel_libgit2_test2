load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
   name = "rules_foreign_cc",
   strip_prefix = "rules_foreign_cc-master",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/master.zip",
)

load("@rules_foreign_cc//:workspace_definitions.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

http_archive(
   name = "libgit2",
   strip_prefix = "libgit2-1.0.1",
   urls = ["https://github.com/libgit2/libgit2/releases/download/v1.0.1/libgit2-1.0.1.tar.gz"],
   build_file = "@//:BUILD.libgit2",
)
