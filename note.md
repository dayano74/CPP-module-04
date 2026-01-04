## CPP-module04

## ex00

### なぜWrongCatはWrongAnimalの音を出力するのか？

`virtual`キーワードを付けていないため、WrongCatはWrongAnimalの音を出力する。

これは**静的バインディング（コンパイル時バインディング）** と **動的バインディング（実行時バインディング）** の違い：

#### `virtual`がない場合（WrongAnimal/WrongCat）
- ポインタの型（WrongAnimal*）に基づいてコンパイル時に関数が決定される
- WrongAnimal::makeSound()が呼ばれる
- **静的バインディング**

#### `virtual`がある場合（Animal/Cat）
- 実際のオブジェクトの型（Cat）に基づいて実行時に関数が決定される
- Cat::makeSound()が呼ばれる
- **動的バインディング**

```cpp
WrongAnimal* wrongCat = new WrongCat();
wrongCat->makeSound(); // WrongAnimal の音（ポインタの型で決定）

Animal* cat = new Cat();
cat->makeSound(); // Cat の音（実際のオブジェクトの型で決定）
```

**結論**: ポリモーフィズム（多態性）を正しく機能させるために`virtual`が必要。


### なぜvirtualが必要なのか？

`virtual`が必要な理由は、**基底クラスのポインタや参照を通じて派生クラスの正しいメソッドを呼び出すため**。

#### `virtual`がない場合の問題

```cpp
Animal* animal = new Cat();
animal->makeSound();  // Catの鳴き声を期待
delete animal;        // Catのデストラクタを期待
```

`virtual`がないと：
- `animal`のポインタ型は`Animal*`
- コンパイラは**ポインタの型**だけを見て、`Animal::makeSound()`を呼ぶ
- `Animal`のデストラクタだけが呼ばれ、`Cat`のデストラクタは呼ばれない（メモリリーク）

#### `virtual`がある場合

```cpp
class Animal {
    virtual void makeSound() { ... }
    virtual ~Animal() { ... }
};
```

- コンパイラは**仮想関数テーブル（vtable）** を作成
- 実行時に**実際のオブジェクトの型**（この場合`Cat`）を確認
- `Cat::makeSound()`と`Cat`のデストラクタが正しく呼ばれる

#### 実用的な理由

1. **ポリモーフィズム**: 異なる派生クラスを同じ基底クラスのポインタで扱える
2. **安全なメモリ管理**: デストラクタが正しく呼ばれる
3. **柔軟な設計**: 基底クラスのインターフェースで、派生クラス固有の動作を実現

**重要**: 継承を使う場合、基底クラスのデストラクタは必ず`virtual`にすべき。


## ex01

### Deep CopyとShallow Copyの違い

要点：
- Shallow Copy: ポインタのアドレスだけコピー → 同じメモリを共有 → 危険
- Deep Copy: ポインタが指す内容もコピー → 独立したメモリ → 安全


#### Shallow Copy（浅いコピー）

ポインタの**アドレス値だけ**をコピーする。コピー元とコピー先が**同じメモリ領域を指す**。

```cpp
class Dog {
    Brain* brain;
public:
    // Shallow Copyの例（デフォルトのコピーコンストラクタ）
    Dog(const Dog& other) : brain(other.brain) {
        // brainのアドレスだけコピー
    }
};

Dog dog1;
Dog dog2(dog1);  // dog1.brainとdog2.brainは同じメモリを指す
dog2.brain->ideas[0] = "新しいアイデア";  // dog1のbrainも変更される！
delete dog1.brain;  // dog2.brainも無効になる（ダングリングポインタ）
```

**問題点**:
- 一方を変更すると、もう一方も影響を受ける
- 一方を削除すると、もう一方が無効なメモリを参照（クラッシュの原因）
- デストラクタで二重解放（double free）が発生

#### Deep Copy（深いコピー）

ポインタが指す**メモリ領域の内容**もコピーする。コピー元とコピー先が**独立したメモリ領域を持つ**。

```cpp
class Dog {
    Brain* brain;
public:
    // Deep Copyの実装
    Dog(const Dog& other) : brain(new Brain(*other.brain)) {
        // 新しいBrainオブジェクトを作成し、内容をコピー
    }

    Dog& operator=(const Dog& other) {
        if (this != &other) {
            delete brain;  // 古いメモリを解放
            brain = new Brain(*other.brain);  // 新しくコピー
        }
        return *this;
    }
};

Dog dog1;
Dog dog2(dog1);  // dog2は独自のBrainを持つ
dog2.brain->ideas[0] = "新しいアイデア";  // dog1には影響しない
delete dog1.brain;  // dog2.brainは影響を受けない
```

**利点**:
- オブジェクトが完全に独立
- 一方の変更が他方に影響しない
- メモリ管理が安全

#### まとめ

| 項目 | Shallow Copy | Deep Copy |
|------|-------------|-----------|
| コピー対象 | ポインタのアドレス | ポインタが指す内容 |
| メモリ | 共有される | 独立している |
| 独立性 | なし | あり |
| 安全性 | 低い（二重解放のリスク） | 高い |
| 実装 | 簡単（デフォルト） | 手動実装が必要 |

**重要**: ポインタメンバを持つクラスでは、必ずDeep Copyを実装すべき。


