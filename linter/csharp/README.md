# 🛡️ C# Secure Coding Setup

This linter pipeline ensures that all C# code follows basic safety, maintainability, and formatting rules using:

- **dotnet format**: automatic formatting and style enforcement
- **Roslynator**: static analysis with focus on real-world issues
- **dotnet build**: strict compile-time checks with `--warnaserror`

---

## 📁 How to Integrate into Your Project

1. Copy the following files into your project:
   - `.editorconfig`
   - `.roslynator.json`
   - `.gitlab-ci.yml`
   - `Dockerfile_dotnet`

2. Update the `.gitlab-ci.yml` paths to match your source structure (e.g., `src/` and the *.proj filename).

3. Ensure Docker image upload is supported by your GitLab Container Registry, or rebuild it for each run.

---

## ✅ Rules Enforced

### Primary Rulesets
- **Roslynator**: Efficient C# static code analysis with hundreds of clean-up and refactoring rules.
- **dotnet format**: Enforces `.editorconfig`-based style guidelines (formatting, spacing, indentation).
- **MSBuild** (via `dotnet build --warnaserror`): Enforces strict compile-time validation.

### Key Enforced Practices

- All compiler warnings are treated as errors
- Use of `const` for immutable local variables (`RCS1118`)
- Prefer `foreach` over index-based `for` (`RCS1080`)
- Conditional access (`?.`) instead of null-checks (`RCS1146`)
- Unused members flagged as warnings (`RCS1213`)
- Spacing, indentation, and line wrapping via `.editorconfig`
- Fail-fast builds to surface issues early in CI

> The `.roslynator.json` and `.editorconfig` files define project-specific linter behavior. You can version these for consistent enforcement across your team.

--- 

## 🧪 Pipeline Overview

| Stage  | Tool            | Purpose                                |
|--------|-----------------|----------------------------------------|
| build  | dotnet build    | Ensures no compiler warnings or errors |
| lint   | dotnet format   | Checks formatting consistency          |
| lint   | roslynator      | Analyzes code for anti-patterns        |

## 🚀 Usage (CI/CD)

The CI pipeline will:

1. Restore dependencies
2. Check formatting with `dotnet format`
3. Run static analysis with `roslynator`
4. Build the code with all warnings treated as errors

If **any** of these steps fail, the merge is blocked.

All lint warnings are treated as errors.

---

## 📎 Example Project

The `src/` folder contains an intentionally flawed example project. It demonstrates how the linter detects issues.

> This is not production code. It's meant for demo and testing. You can remove or replace it after integration.

---

## 📚 Documentation

For detailed policies and rule justifications, refer to the official SOP:  
🔗 [C# Coding Guidelines SOP](/SCSharp/)

For rule documentation:  
🔗 [Roslynator Analyzer Rules](https://github.com/JosefPihrt/Roslynator/blob/master/docs/analyzers.md)  
🔗 [dotnet-format documentation](https://learn.microsoft.com/en-us/dotnet/devops/dotnet-format)  
🔗 [C# Compiler Warnings (MSBuild)](https://learn.microsoft.com/en-us/dotnet/fundamentals/code-analysis/compiler-warnings)

> Tip: You can configure `dotnet build` to treat *all warnings* as errors via `--warnaserror` or fine-tune per rule in `.csproj` with `<WarningsAsErrors>`.

