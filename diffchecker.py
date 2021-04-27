

# a is expected, b is actual
def diffChr(a, b):
    if len(a) != len(b):
        print(f"len(exp)={len(a)}, len(act)={len(b)}")
    resa = resb = ""
    for i in range(len(a)):
        if a[i] != b[i]:
            resa += f"\033[44;33m{a[i]}\033[m"
            resb += f"\033[44;33m{b[i]}\033[m"
        else:
            resa += a[i]
            resb += b[i]
    print(f"expect={resa}")
    print(f"actual={resb}")


if __name__ == '__main__':
    exp = "wjwjwjpmadpmadpmadpmadpmadfqpmadpmadpmadpmadpmadfqpmadpmadpmadpmadpmadfqpmadpmadpmadpmadpmadfqpshapmadpmadpmadpmadpmadfqpmadpmadpmadpmadpmadfqpmadpmad"
    act = "wjwjwjpmadpmadpmadpmadpmadfqfqfqfqpshashafxbsfxbsfxbsnbgamwrgamwrzzzzpmadpmadpmadpmadpmadfqfqfqfqpshashafxbsfxbsfxbsnbgamwrgamwrzzzzsthmlsthmlsthmlsthml"
    diffChr(exp, act)
