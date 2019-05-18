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

得られたデータは1行目に全データの件数、それ以降の各行に以下の7つの情報がスペース区切りで含まれる。

* ID
* メニュー名 (文字列)
* カテゴリ (文字列)
* 種類 (文字列)
* 価格 (円)
* カロリー (kcal)
* 塩分 (g)

```bash
head -n 5 saizeriya.txt
```

```
114
1 彩りガーデンサラダ sidedish salad 299 130 1.1
2 小エビのサラダ sidedish salad 349 115 1.3
3 やわらかチキンのサラダ sidedish salad 299 134 1.2
4 わかめサラダ sidedish salad 299 92 2.1
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

## 結果

同じメニューは1度しか注文できないという条件の場合:

```
ポテトのグリル: 199円, 366 kcal
アーリオ・オーリオ(Wサイズ): 574円, 1120 kcal
ラージライス: 219円, 454 kcal
合計: 992円, 1940 kcal
```

同じメニューを複数回注文できるという条件の場合:

```
フォッカチオ: 119円, 214 kcal
ラージライス: 219円, 454 kcal
ラージライス: 219円, 454 kcal
ラージライス: 219円, 454 kcal
ラージライス: 219円, 454 kcal
合計: 995円, 2030 kcal
```


## 関連記事

* [サイゼリヤ1000円ガチャをつくってみた(Heroku + Flask + LINEbot) - Qiita](https://qiita.com/marusho_summers/items/a2d3681fac863734ec8a)
* [「サイゼリヤで1000円あれば最大何kcal摂れるのか」を量子アニーリング計算(Wildqat)で解いてみた。 - Qiita](https://qiita.com/hodaka0714/items/cf44b4ece992a39b5be4#_reference-bc420f6e5fbf164bf9a8)
* [「サイゼリヤで1000円あれば最大何kcal摂れるのか」をSMTソルバー(Z3)で解いてみた。 - Qiita](https://qiita.com/tanakh/items/a1fb13f78e0576415de3#_reference-db9f04e4502c2f29e690)
* [「サイゼリヤで1000円あれば最大何kcal摂れるのか」を整数計画法ソルバー(PuLP)で解いてみた。 - Qiita](https://qiita.com/YSRKEN/items/dfc8604eb8598e5e9076#_reference-402a3afaa23678a3d78c)
