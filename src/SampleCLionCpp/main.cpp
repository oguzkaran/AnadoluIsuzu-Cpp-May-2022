/*----------------------------------------------------------------------------------------------------------------------
    Sınıflararası ilişkiler: Sınıflararası ilişkiler aslında nesneler arasındaki ilişkileri temsil eder. Örneğin
    araba ile motoru arasında bir ilişki vardır. Ya da insan ile kimlik kartı arasında bir ilişki vardır. Ya da
    araç ile sürücüsü arasında da bir ilişki vardır. Dikkat edilirse bu ilişkiler nesnelere göre tanımlanır. Ancak nesnelerin
    bu ilişkilerini belirlemek için sınıfların buna uygun olarak yazılması gerekir.

    Nesne yönelimli programlama tekniği kullanılarak yapılacak bir projenin kodlama aşamasından önce sınıflar ve sınıflararası
    ilişkiler belirlenir ve sonrasında kodlamaya geçilir. Sınıflar ve aralarındaki ilişkiler sınıfların/nesnelerin
    gerçek durumları (domain'e göre durumları) düşünülerek belirlenir.

    Anahtar Notlar: Bir projenin müşteri ile görüşülmesinden (requirement analysis denebilir) teslimine (deployment)
    kadar geçen süreci çeşitli şemalarla anlatan UML (Unified Modeling Language) denilen bir araç bazı durumlarda
    kullanılabilmektedir. Bu aracın önemli şemalarından biri "sınıf şemaları (class diagram)"'dır. Bu şema tamamen
    kodlamaya yöneliktir. Sınıf şemalar sınıfların aralarındaki ilişkileri de gösterir.

    Anahtar Notlar: Kavram ya da kavramlar modellenirken o kavramın genel durumu düşünülür. İstisna niteliğinde olacak
    durumlar modelleme yapılırken göz önünde bulundurulmaz. Aksi taktirde hiçbir şey modellenemez. Örneğin araba ile
    motor arasındaki ilişki için şu kuralar söylenebilir:
        1. Araba nesnesine ait olan motor nesnesi başka bir araba ya da araç tarafından kullanılmayacak
        2. Araba nesnesine ait olan motor nesnesi ömrüne hemen hemen arba ile başlayacak ve araba ile ömrü son bulacak
    Burada örneğin ikinci koşul her zaman gerçeklenmeyebilir. Ancak ilişkinin bütününü etkilemez

    Anahtar Notlar: Bir kod parçasının derlenebilmesi için başa bir isme ihtiyaç duyması durumuna "dependency" denir.
    Örneğin bir sınıfın derlenebilmesi için kullandığı sınıfın daha önceden bildirilmiş olması gerekir. Burada bildirim
    "forward declaration" olarak da duruma göre yapılabilir.

    İki sınıf arasında ya hiçbir ilişki yoktur ya da aşağıdakilerden birisi vardır.
    1. Composition (has a): A ve B arasındaki "A has a B" ilişkisi için aşağıdaki iki koşulunda sağlanması gereir, ya da
    aşağıdaki iki koşul sağlanırsa "A has a B" ilişkisi vardır denir:
        - A nesnesine ait olan B nesnesi başka bir nesne tarafından kullanılmayacak
        - A nesnesine ait olan B nesnesi ömrüne hemen heman A ile başlayacak ve hemen hemen A ile ömrü son bulacak
    Bu ilişkide A nesnei kendisine ait olan B nesnesini istediği durumda kullanabilmektedir. Buna "whole usage" denir.

    2. Aggregation (holds a): A ve B arasındaki "A holds a B" ilişkisi composition kurallarının en az bir tanesinin
    genel olarak gerçeklenmediği bütünsel kullanım ilişkisidir.

    3. Association
    4. Inheritance:

    Anahtar Notlar: Yukarıdaki ilişkiler "inheritance" hariç C++'ın şu ana kadar gördüğümüz sentaks ve semantik kuralları,
    ilişkinin kuralları doğrutusunda kullanılarak gerçekleştirilebilir. Ancak inheritance ilişkisi için C++'ın ayrı sentaks
    ve semantik kuralları vardır.

    Anahtar Notlar: Bazı sınıflar implementasyonları gereği yukarıdaki ilişkilerden hiçbirisine uygun olmayabilir. Ama
    ortada yine bir "dependency" söz konusudur. Ancak bu da genel durumu bozmaz
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cstdint>

class Engine {
private:
    //...
public:
    void startEngine();
    void accelerateEngine();
    void slowEngine();
    void stopEngine();
};

void Engine::startEngine()
{
    std::cout << "Engine::startEngine\n";
}

void Engine::accelerateEngine()
{
    std::cout << "Engine::accelerateEngine\n";
}

void Engine::slowEngine()
{
    std::cout << "Engine::slowEngine\n";
}

void Engine::stopEngine()
{
    std::cout << "Engine::stopEngine\n";
}

class Driver {
    friend std::ostream &operator<<(std::ostream &os, const Driver &d);
private:
    std::uint32_t m_id;
    std::string m_name;
    std::size_t m_rating;
    //...
public:
    explicit Driver(std::uint32_t id, const char *name, std::size_t rating) : m_id{id}, m_name{name}, m_rating{rating}
    {}

    //...
    std::uint32_t id() const {return m_id;}
    std::string name() const {return m_name;}
    std::size_t rating() const {return m_rating;}
    //...
};

std::ostream &operator<<(std::ostream &os, const Driver &d)
{
    return os << "[" << d.m_id << "]" << d.m_name << ", " << d.m_rating;
}

class Car {
private:
    Engine m_engine;
    Driver *m_driver;
public:
    explicit Car(Driver &driver /*...*/) : m_engine{/*...*/}, m_driver{&driver}
    {}

    void driver(Driver &d);
    Driver *driver() const {return m_driver;}
    void brake();
    void run();
};

void Car::driver(Driver &d)
{
    //...
    m_driver = &d;
}


void Car::brake()
{
    m_engine.slowEngine();
}

void Car::run()
{
    std::cout << *m_driver << '\n';
    m_engine.startEngine();
    m_engine.accelerateEngine();
    std::cout << "running\n";
    //...
    brake();
    m_engine.stopEngine();
}

class Pilot {
    friend std::ostream &operator<<(std::ostream &os, const Pilot &p);
private:
    std::uint16_t m_title;
    std::string m_name;
    std::size_t m_flightHour;
public:
    Pilot(std::uint16_t title = 0, const char *name = nullptr, std::size_t flightHour = 0) : m_title{title}, m_name{name}, m_flightHour{flightHour}
    {}

    //...

    std::uint16_t title() const {return m_title;}
    std::string name() const {return m_name;}
    std::size_t flightHour() const {return m_flightHour;}
    //...
};

std::ostream &operator<<(std::ostream &os, const Pilot &p)
{
    return os << "(" << p.m_title << ")" << p.m_name << ", " << p.m_flightHour;
}

class Plane {
private:
    std::size_t m_engineCount;
    Engine *m_engines;
    Pilot m_pilots[3];
public:
    Plane(std::size_t count, const Pilot *pilots /*...*/)  : m_engineCount{count}, m_engines{new Engine[count]}
    {
        for (int i{}; i < 3; ++i)
            m_pilots[i] = pilots[i];
    }

    Plane(const Plane &) = delete;
    Plane &operator=(const Plane &) = delete;
    //...

    ~Plane()
    {
        if (m_engines)
            delete [] m_engines;
    }
public:
    void startEngines();
    void accelerateEngines();
    void slowEngines();
    void stopEngines();
    void fly();
};

void Plane::startEngines()
{
    for (std::size_t i{}; i < m_engineCount; ++i)
        m_engines[i].startEngine();
}

void Plane::accelerateEngines()
{
    for (std::size_t i{}; i < m_engineCount; ++i)
        m_engines[i].accelerateEngine();
}

void Plane::slowEngines()
{
    for (std::size_t i{}; i < m_engineCount; ++i)
        m_engines[i].slowEngine();
}

void Plane::stopEngines()
{
    for (std::size_t i{}; i < m_engineCount; ++i)
        m_engines[i].stopEngine();
}

void Plane::fly()
{
    using std::cout;

    cout << "Pilots:\n";
    for (const auto &p : m_pilots)
        cout << p << '\n';

    cout << "--------------------------\n";

    startEngines();
    accelerateEngines();

    //...

    cout << "Flying\n";

    slowEngines();
    stopEngines();

    cout << "--------------------------\n";
}


int main()
{
    using namespace std;

    Driver d1{1, "Ali", 10};
    Driver d2{2, "Veli", 3};
    Driver d3{3, "Selami", 4};
    Car car{d1/*...*/};

    car.run();
    car.driver(d2);
    car.run();
    car.driver(d3);
    car.run();

    cout << "###############################################\n";

    Pilot pilots[] {Pilot{1, "Deniz", 10000}, Pilot{2, "Şeyma", 50000}, Pilot{3, "Oguz", 2000}};
    Plane plane{4, pilots};

    plane.fly();

    return 0;
}

