#include <cstdio>
#include <git2.h>

int main() {
  git_libgit2_init();

  git_repository *repo = nullptr;

  git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;
	git_checkout_options checkout_opts = GIT_CHECKOUT_OPTIONS_INIT;

  int error;

  checkout_opts.checkout_strategy = GIT_CHECKOUT_SAFE;
	clone_opts.checkout_opts = checkout_opts;

  error = git_clone(&repo, "https://github.com/whs-dot-hk/ansible-fedora-32.git", "test", &clone_opts);
  if (error != 0) {
		const git_error *err = git_error_last();
		if (err) {
      printf("ERROR %d: %s\n", err->klass, err->message);
    }
	}

  git_repository_free(repo);

  git_libgit2_shutdown();
}
