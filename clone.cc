#include <git2.h>
#include <fmt/core.h>
#include <fmt/printf.h>
#include <memory>

int cb(git_credential **out, const char* a, const char* b, unsigned int c, void* d) {
  return git_credential_userpass_plaintext_new(out, std::getenv("GITHUB_USERNAME"), std::getenv("GITHUB_ACCESS_TOKEN"));
}

struct R {
  git_repository *repo = nullptr;

  git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;
  git_checkout_options checkout_opts = GIT_CHECKOUT_OPTIONS_INIT;

  R() {
    git_libgit2_init();

    checkout_opts.checkout_strategy = GIT_CHECKOUT_SAFE;
    clone_opts.checkout_opts = checkout_opts;
    clone_opts.fetch_opts.callbacks.credentials = cb;

  }

  int clone(const std::string& service_name) {
    std::string url = fmt::sprintf("https://github.com/SeekersAdvisorsLabs/%s.git", service_name);

    return git_clone(&repo, url.c_str(), service_name.c_str(), &clone_opts);
  }

  ~R() {
    git_repository_free(repo);
    git_libgit2_shutdown();
  }
};

int main(int argc, char** argv) {
  if (argc <= 1) {
    fmt::print("Missing service name\n");
    exit(1);
  }

  if (std::getenv("GITHUB_USERNAME") == nullptr) {
    fmt::print("Missing github username\n");
    exit(1);
  }

  if (std::getenv("GITHUB_ACCESS_TOKEN") == nullptr) {
    fmt::print("Missing github password\n");
    exit(1);
  }

  std::string service_name = argv[1];

  auto p = std::make_unique<R>();

  int error = p->clone(service_name);
  if (error != 0) {
    const git_error *err = git_error_last();
    if (err) {
      fmt::printf("ERROR %d: %s\n", err->klass, err->message);
    }
  }

  return 0;
}
