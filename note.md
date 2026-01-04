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




## ex02

### 抽象化とは？

**抽象化（Abstraction）** とは、**具体的な実装の詳細を隠して、重要な概念や機能だけを表現する**プログラミングの技法。

#### 日常の例
- **「動物」**: 抽象的な概念。実際には「犬」「猫」などの具体的な動物しか存在しない
- **「乗り物」**: 抽象的な概念。実際には「車」「電車」「飛行機」などが存在する

#### C++での抽象化

##### 1. 抽象クラス（Abstract Class）
少なくとも1つの**純粋仮想関数**を持つクラス。インスタンス化できない。

```cpp
class Animal {  // 抽象クラス
public:
    virtual void makeSound() const = 0;  // 純粋仮想関数
    virtual ~Animal() {}
};

// Animal animal;  // エラー！抽象クラスはインスタンス化できない
```

##### 2. 具象クラス（Concrete Class）
抽象クラスを継承し、すべての純粋仮想関数を実装したクラス。インスタンス化できる。

```cpp
class Dog : public Animal {  // 具象クラス
public:
    void makeSound() const override {  // 実装を提供
        std::cout << "Woof!" << std::endl;
    }
};

Dog dog;  // OK！具象クラスはインスタンス化できる
```

#### 抽象化の利点

1. **インターフェースの統一**
   ```cpp
   Animal* animals[2];
   animals[0] = new Dog();
   animals[1] = new Cat();

   for (int i = 0; i < 2; i++) {
       animals[i]->makeSound();  // 統一されたインターフェース
   }
   ```

2. **不正なインスタンス化を防ぐ**
   ```cpp
   // Animal animal;  // コンパイルエラー
   // 「抽象的な動物」は存在しないので、これは正しい制約
   ```

3. **設計の明確化**
   - 基底クラスは「何をすべきか」を定義（インターフェース）
   - 派生クラスは「どうやるか」を実装（具体的な動作）

#### まとめ

| 概念 | 説明 | 例 |
|------|------|-----|
| **抽象化** | 詳細を隠し、本質だけを表現 | Animal（抽象） |
| **具象化** | 具体的な実装を提供 | Dog, Cat（具象） |
| **純粋仮想関数** | `= 0`で宣言された関数 | `virtual void makeSound() = 0;` |
| **抽象クラス** | 純粋仮想関数を持つクラス | インスタンス化不可 |

**ex02の目的**: `Animal`は抽象的な概念なので、直接インスタンス化できないようにする（抽象クラス化）。


### 純粋仮想関数とは？

**純粋仮想関数（Pure Virtual Function）** とは、**実装を持たず、派生クラスで必ず実装しなければならない関数**のこと。

#### 構文

```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // 純粋仮想関数
    //                              ^^^^
    //                              これが純粋仮想関数の印
};
```

`= 0` を付けることで、「この関数は実装を持たない」ことを宣言する。

#### 通常の仮想関数との違い

##### 通常の仮想関数
```cpp
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Some sound" << std::endl;  // 実装がある
    }
};

Animal animal;  // OK！インスタンス化できる
```

##### 純粋仮想関数
```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // 実装がない
};

Animal animal;  // エラー！インスタンス化できない
```

#### 純粋仮想関数の目的

1. **抽象クラスを作る**
   - 少なくとも1つの純粋仮想関数があると、そのクラスは抽象クラスになる
   - 抽象クラスは直接インスタンス化できない

2. **派生クラスに実装を強制する**
   ```cpp
   class Dog : public Animal {
   public:
       void makeSound() const override {  // 必ず実装が必要
           std::cout << "Woof!" << std::endl;
       }
   };

   // もし実装しなければ、Dogも抽象クラスになる
   ```

3. **インターフェースを定義する**
   - 基底クラスは「何をすべきか」だけを定義
   - 派生クラスが「どうやるか」を実装

#### 実例

```cpp
class Shape {  // 抽象クラス
public:
    virtual double area() const = 0;      // 純粋仮想関数
    virtual double perimeter() const = 0; // 純粋仮想関数
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14 * radius;
    }
};

// Shape shape;      // エラー！
Circle circle(5.0);  // OK！
```

#### まとめ

| 項目 | 通常の仮想関数 | 純粋仮想関数 |
|------|--------------|------------|
| 宣言 | `virtual void func()` | `virtual void func() = 0` |
| 実装 | あり（基底クラスに） | なし |
| オーバーライド | 任意 | 必須 |
| クラスの性質 | 具象クラス | 抽象クラス |
| インスタンス化 | 可能 | 不可能 |

**重要**: 純粋仮想関数は、派生クラスに特定の関数の実装を強制するための仕組み。



## ex03


