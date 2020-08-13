load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
   name = "rules_foreign_cc",
   strip_prefix = "rules_foreign_cc-master",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/master.zip",
)

load("@rules_foreign_cc//:workspace_definitions.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

http_archive(
    name = "io_bazel_rules_docker",
#    sha256 = "4521794f0fba2e20f3bf15846ab5e01d5332e587e9ce81629c7f96c793bb7036",
    strip_prefix = "rules_docker-master",
    urls = ["https://github.com/henrywong-seekers/rules_docker/archive/master.zip"],
)

load(
    "@io_bazel_rules_docker//repositories:repositories.bzl",
    container_repositories = "repositories",
)
container_repositories()

load("@io_bazel_rules_docker//repositories:deps.bzl", container_deps = "deps")

container_deps()

load("@io_bazel_rules_docker//repositories:pip_repositories.bzl", "pip_deps")

pip_deps()

load(
    "@io_bazel_rules_docker//container:container.bzl",
    "container_pull",
)

container_pull(
    name = "debian_image",
    digest = "sha256:32ddd50533c65dc3a1fba9a69c7fc43ca95460b77ccefed8587e17415a41a267",  # bullseye-20200803
    registry = "index.docker.io",
    repository = "debian",
)

load(
    "@io_bazel_rules_docker//cc:image.bzl",
    _cc_image_repos = "repositories",
)

_cc_image_repos()

http_archive(
   name = "libgit2",
   strip_prefix = "libgit2-1.0.1",
   urls = ["https://github.com/libgit2/libgit2/releases/download/v1.0.1/libgit2-1.0.1.tar.gz"],
   build_file = "@//:BUILD.libgit2",
)

http_archive(
   name = "fmt",
   strip_prefix = "fmt-7.0.3",
   urls = ["https://github.com/fmtlib/fmt/releases/download/7.0.3/fmt-7.0.3.zip"],
   build_file = "@//:BUILD.fmt",
)
