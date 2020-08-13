load("@io_bazel_rules_docker//docker/package_managers:download_pkgs.bzl", "download_pkgs")
load("@io_bazel_rules_docker//docker/package_managers:install_pkgs.bzl", "install_pkgs")

load("@io_bazel_rules_docker//container:container.bzl", "container_image")

download_pkgs(
    name = "cacerts_pkg",
    image_tar = "@debian_image//image",
    packages = [
        "ca-certificates",
    ],
)

install_pkgs(
    name = "cacerts_pkg_image",
    image_tar = "@debian_image//image",
    installables_tar = ":cacerts_pkg.tar",
    installation_cleanup_commands = "rm -rf /var/lib/apt/lists/*",
    output_image_name = "cacerts_pkg_image",
)

container_image(
    name = "cacerts_wrapper",
    base = ":cacerts_pkg_image.tar",
)

load("@io_bazel_rules_docker//cc:image.bzl", "cc_image")

cc_image(
    name = "cc_image_clone",
    srcs = ["clone.cc"],
    deps = [
      "@libgit2//:libgit2",
      "@fmt//:fmt",
    ],
    base = ":cacerts_wrapper",
)

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_binary(
    name = "bin",
    srcs = ["clone.cc"],
    deps = [
      "@libgit2//:libgit2",
      "@fmt//:fmt",
    ],
)
