# saizeriya-1000yen-knapsack

「サイゼリヤで1000円あれば最大何kcal摂れるのか」を動的計画法で解いてみた


## メニューデータの取得

「サイゼリヤ1000円ガチャ」さんの GitHub リポジトリからデータをお借りする。
https://github.com/marushosummers/Saizeriya_1000yen

```bash
curl https://raw.githubusercontent.com/marushosummers/Saizeriya_1000yen/master/sensai/saizeriya.db > saizeriya.db
```

取得したデータは sqlite3 のデータベースファイル(？)のようなのでテキストファイルに変換する。

```bash
python3 convert.py > saizeriya.txt
```


## 最適な組み合わせを求める

同じメニューは1度しか注文できないという条件の場合:

```bash
g++ solve.cpp -o solve
./solve < saizeriya.txt
```

同じメニューを複数回注文できるという条件の場合:

```bash
g++ solve_duplicate.cpp -o solve_duplicate
./solve_duplicate < saizeriya.txt
```
