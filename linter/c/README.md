# Clang-Tidy CERT Linting for C Projects

This setup integrates `clang-tidy` with the CERT rule set for secure and safe code practices, especially suitable for domains like medical software (MedTech). It is compatible with both Visual Studio and VSCode, and integrates cleanly with GitLab CI.

---

## 📁 How to Integrate into Your Project

1. Copy the following files and folders into your project:
   - `.clang-tidy`
   - `.clang-format`
   - `.gitlab-ci.yml`
   - `Dockerfile_clang`

2. Adjust paths in `.gitlab-ci.yml` to reflect your actual source structure (e.g., `src` folder).

3. Make sure your CI environment has write access to a Docker registry (GitLab: Container Registry) to upload the created image. Else you have to build the image for every run.

### 📎 Examples

The `src` folder contains an example project, intentionally flawed code examples to showcase how `clang-tidy` and `clang-format` catches typical issues. These help test and visualize the linting process.

They are **not production code** and are purely educational. Feel free to remove them when setting up for your real project.

The CI will fail because of the codesmells, feel free to fix it (in your clone of the project) to see how the linter/formatter works.

---

## ✅ Enabled Rules & Why They Matter

### Rule Set: **CERT** (SEI CERT C Coding Standard)
- Focuses on secure coding practices to prevent common vulnerabilities such as:
  - Buffer overflows
  - Data races
  - Undefined behavior
- Helps meet requirements in safety-critical software environments

### Additional Suggestions
You can enable more checks in the `.clang-tidy` file by adjusting the `Checks:` key.
For example:
```yaml
Checks: '-*,cert-*'
```
Or add more:
```yaml
Checks: '-*,cert-*,clang-analyzer-*,cppcoreguidelines-*'
```

Find the full list of checks here:
🔗 [Clang-Tidy Checkers](https://clang.llvm.org/extra/clang-tidy/checks/list.html)

---

## 🧹 About the `.clang-format` File

The `.clang-format` file ensures a consistent coding style across C files. It can be used in Visual Studio, VSCode, or from CLI with `clang-format -i your_file.c`.

Find the full documentation here:
🔗 [Clang-Tidy Formatter](https://clang.llvm.org/docs/ClangFormat.html)

---

## ⚙️ GitLab CI/CD Pipeline Explanation

The pipeline builds a Docker image with `clang-tidy` and `clang-format` installed and uses it to lint the C++ files.

### Pipeline Stages
- **prep_env**: Prepare the docker image
- **build**: Builds the C Example Project
- **lint**: Lints the C source files using appropriate `.clang-*` configs

---

This setup is maintained with flexibility and security in mind. The goal is to provide an extendable, CI-ready base for secure software development across multiple programming languages.
