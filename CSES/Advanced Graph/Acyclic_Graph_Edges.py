n, m = map(int, input().split())
for _ in range(m):
  u,v = map(int,input().split())
  print(f'{u} {v}' if u<v else f'{v} {u}')