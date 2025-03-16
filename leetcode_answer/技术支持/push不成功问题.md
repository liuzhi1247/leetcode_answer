# 通过设置系统代理解决 Git 连接问题

如果在使用 Git 时遇到连接问题，可以通过设置系统代理来解决。以下是具体步骤：

## 步骤 1：搜索代理

1. 打开系统设置，搜索“代理”。
2. 选择“手动设置代理”。
3. 启用“使用代理服务器”选项。
4. 在代理服务器设置中，将端口设置为 `7890`（这个端口不会影响正常上网，可以放心设置）。
5. 点击“保存”。

## 步骤 2：在终端设置 Git 使用本地代理

1. 打开终端（例如 PowerShell 或 Git Bash）。
2. 输入以下命令，设置 Git 使用本地代理：
   ```sh
   git config --global http.proxy http://127.0.0.1:7890
   ```

## 步骤 3：检验设置是否成功

1. 在终端输入以下命令，查看当前 Git 配置：
   ```sh
   git config --global -l
   ```
2. 检查输出中是否包含以下内容：
   ```sh
   http.proxy=http://127.0.0.1:7890
   ```

## 使用过程示例

以下是一个设置代理和推送代码的示例过程：

```sh
PS C:\Users\25245\OneDrive\Desktop\vscode files\leetcode_answer> git push origin main:main
fatal: unable to access 'https://github.com/liuzhi1247/leetcode_answer.git/': Recv failure: Connection was reset

PS C:\Users\25245\OneDrive\Desktop\vscode files\leetcode_answer> git config --global http.proxy http://127.0.0.1:7890
PS C:\Users\25245\OneDrive\Desktop\vscode files\leetcode_answer> git config --global -l
user.name=liuzhi1247
user.email=2524587016@qq.com
http.sslverify=false
http.sslbackend=schannel
http.proxy=http://127.0.0.1:7890
PS C:\Users\25245\OneDrive\Desktop\vscode files\leetcode_answer> git push origin main:main
Enumerating objects: 13, done.
Counting objects: 100% (13/13), done.
Delta compression using up to 28 threads
Compressing objects: 100% (10/10), done.
Writing objects: 100% (11/11), 2.08 KiB | 2.08 MiB/s, done.
Total 11 (delta 3), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (3/3), completed with 1 local object.
To https://github.com/liuzhi1247/leetcode_answer.git
   8e98014..aa9effd  main -> main
```

通过以上步骤，你应该能够解决由于网络连接问题导致的 Git 访问错误。如果问题仍然存在，可以考虑联系网络管理员或 GitHub 支持。