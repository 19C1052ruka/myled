# myled
## リポジトリ概要
-2020年度ロボットシステム学、課題１の提出ファイルです。
## 目的
- 7セグを使いカウントダウンをします
##  使用環境 
  Ubuntu20.04LTS
##  使用機材　
- RaspberryPi4
- 5mmLED
- ブレットボード
- デュポン線
- 20Pジャンパー線
- 7セグメント
- 抵抗器(220Ω)
## インストール手順
- `git clone https://github.com/sakurai-ruka/kadai1.git`
##  実行方法
  実行方法は上から順にコマンドを打つ
  - `cd kadai1`
  - `make`
  - `sudo insmod myled.ko`
  - `sudo chmod 666 /dev/myled0`
  - `echo 0 > /dev/myled0`
##  実行結果
  - 実行結果はecho 0 > /dev/myled0を実行した時、７セグメントに5から0まで順に表示され数字が切り替わるごとに対応するLEDが光る。
  また、echo 1 > /dev/myled0を実行した場合全てのLEDが消える。
  5から0までは１秒ごとに切り替わる。
## デモ動画
- https://www.youtube.com/watch?v=9QS34k75HV0&feature=youtu.be
## ライセンス
- GNU General Public Licence v3.0
