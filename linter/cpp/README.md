# Clang-Tidy CERT Linting for C++ Projects

This setup enforces secure and consistent C++ coding practices using `clang-tidy` and the CERT rule set. It is tailored for medical device software development and aligns with the [C++ Coding Guidelines SOP](/SC++/).

---

## 📁 How to Integrate into Your Project

1. Copy the following files into your project:
   - `.clang-tidy`
   - `.clang-format`
   - `.gitlab-ci.yml`
   - `Dockerfile_clang`

2. Update the `.gitlab-ci.yml` paths to match your source structure (e.g., `src/`).

3. Ensure Docker image upload is supported by your GitLab Container Registry, or rebuild it for each run.

---

## ✅ Rules Enforced

### Primary Rulesets
- **CERT**: Secure C++ coding practices (e.g., buffer handling, memory management).
- **cppcoreguidelines**: Modern C++ best practices.
- **clang-analyzer**: Static analysis for undefined or dangerous behavior.
- **readability**: Improves code clarity.

### Key Enforced Practices (see SOP for full list)
- Use of `std::unique_ptr` / `std::shared_ptr`
- RAII-based resource handling
- No global variables
- Const-correctness
- Allman brace style
- 2-space indentation

---

## ⚙️ GitLab CI/CD Pipeline

The pipeline performs:
- **prep_env**: Docker environment setup
- **build**: Build example/test project (optional)
- **lint**: Run `clang-tidy` and `clang-format`

All lint warnings are treated as errors.

---

## 📎 Example Project

The `src/` folder contains an intentionally flawed example project. It demonstrates how the linter detects issues.

> This is not production code. It's meant for demo and testing. You can remove or replace it after integration.

---

## 📚 Documentation

For detailed policies and rule justifications, refer to the official SOP:  
🔗 [C++ Coding Guidelines SOP](/SC++/)

For rule details:  
🔗 [clang-tidy Checkers](https://clang.llvm.org/extra/clang-tidy/checks/)  
🔗 [CERT C++ Rules](https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard)

---

## 📅 Last Reviewed

April 28, 2025 — synced with latest CERT and clang-tidy rule sets.
