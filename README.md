# 🔐 Secure Code Setup Repository

This repository provides linting, formatting, and static analysis setups for multiple programming languages used in secure and safety-critical development — particularly for medical device software (ISO 62304 compliant).

It is designed for integration with GitLab CI/CD pipelines and can be extended to support container scanning and artifact checks in the future.

---

## 📁 Structure Overview

| Path | Description |
|------|-------------|
| `/linter/c` | Setup for C projects using `clang-tidy`, `clang-format`, and CERT rules |
| `/linter/cpp` | Setup for C++ projects using modern guidelines and static analysis |
| `/linter/csharp` | (Planned) Setup for C# projects with security and style analysis |
| `/linter/dart` | (Planned) Dart/Flutter code style enforcement |
| `/scanner/containers` | (Future) Container image security checks (e.g., Trivy) |
| `/scanner/binaries` | (Future) Binary/static artifact scanning |

---

## 🧩 General Philosophy

- Promote **secure-by-default development** with minimal developer friction
- Maintain **regulatory traceability** (e.g., ISO 62304, ISO 14971)
- Use **open tools** (like `clang-tidy`, `trivy`, `dotnet-format`) with CI integration
- Provide **template projects** that demonstrate lint failures and corrections

---

## 🧪 How to Use

Each language folder contains:
- `.clang-tidy` / `.clang-format` (or equivalent)
- Example project under `/src`
- CI pipeline setup (`.gitlab-ci.yml`, Dockerfiles)
- SOP reference for compliance

Follow the `README.md` in each subfolder for detailed integration instructions.

---

## 📚 Related SOPs

- [C Coding Guidelines SOP](/SC/)
- [C++ Coding Guidelines SOP](/SC++/)

---

## 📅 Last Reviewed

April 28, 2025 — structure synced with CERT, clang-tidy, and internal coding SOPs.
