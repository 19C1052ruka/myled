# myled
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
- 'git clone https://github.com/sakurai-ruka/kadai1.git'
##  実行方法
  実行方法は上から順にコマンドを打つ
  - cd kadai1
  - make
  - sudo rmmod myled
  - sudo insmod myled.ko
  - sudo chmod 666 /dev/myled0
  - echo 0 > /dev/myled0
##  実行結果
  実行結果はecho 0 > /dev/myled0を実行した時、７セグメントに5から0まで順に表示され数字が切り替わるごとに対応するLEDが光る。
  また、echo 1 > /dev/myled0を実行した場合全てのLEDが消える。
  5から0までは１秒ごとに切り替わる。
