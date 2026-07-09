#pragma once
#include <random>
#include <iostream>
#include <string>
#include <cctype>

class Irand {
    std::uniform_int_distribution<int> dist;

    static std::mt19937& engine() {
        static std::mt19937 eng{ std::random_device{}() };
        return eng;
    }

public:
    Irand(int min, int max) : dist(min, max) {}

    int operator()() { return dist(engine()); }
};

// cprint'ten ONCE koy
template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p)
{
    return os << p.first << ": " << p.second;
}
template<typename Collection>
void cprint(const Collection& c, const char* psep = " ", std::ostream& os = std::cout)
{
    for (const auto& elem : c)
        os << elem << psep;
    os << '\n';
}




inline std::string random_name() {
    static const char* names[] = {
        "Ahmet", "Mehmet", "Mustafa", "Ali", "Huseyin", "Hasan", "Ibrahim",
        "Osman", "Yusuf", "Murat", "Emre", "Burak", "Kaan", "Berkay",
        "Kerem", "Deniz", "Cem", "Baris", "Onur", "Serkan", "Tolga",
        "Enes", "Furkan", "Yunus", "Eren", "Ege", "Arda", "Efe",
        "Bora", "Tunc", "Volkan", "Gokhan", "Selim", "Sinan", "Ugur",
        "Ozan", "Kadir", "Halil", "Ismail", "Ramazan", "Fatih", "Hakan",
        "Oguz", "Baran", "Cagan", "Doruk", "Alp", "Batu", "Mert",
        "Taha", "Emir", "Yigit", "Kuzey", "Poyraz", "Toprak", "Cinar",
        "Bulut", "Kagan", "Tarik", "Metin", "Bulent", "Cihan", "Devran",
        "Ferhat", "Gorkem", "Harun", "Ilhan", "Kemal", "Levent", "Naci",
        "Necati", "Orhan", "Riza", "Sedat", "Sukru", "Turan", "Unal",
        "Vedat", "Yavuz", "Zafer", "Aslan", "Dogan", "Kartal", "Tugrul",

        "Ayse", "Fatma", "Emine", "Hatice", "Zeynep", "Elif", "Meryem",
        "Merve", "Busra", "Esra", "Derya", "Selin", "Ceren", "Ebru",
        "Sema", "Sevgi", "Gul", "Nur", "Nazli", "Melike", "Sila",
        "Ela", "Defne", "Ada", "Naz", "Ece", "Ipek", "Yagmur",
        "Duru", "Nehir", "Su", "Irmak", "Damla", "Berrak",
        "Asli", "Bahar", "Belma", "Canan", "Dilek", "Ferda", "Gamze",
        "Handan", "Isil", "Jale", "Kubra", "Leyla", "Melek", "Nesrin",
        "Ozge", "Pinar", "Rabia", "Seda", "Seyma", "Tugba", "Ulku",
        "Vildan", "Yasemin", "Zehra", "Aleyna", "Beren", "Cansu", "Dilara",
        "Eylul", "Feyza", "Gizem", "Hande", "Irem", "Kader", "Lale",
        "Melis", "Nisa", "Oyku", "Perihan", "Reyhan", "Simge", "Sevval",
        "Tuana", "Ummu", "Vuslat", "Yaren", "Zeliha", "Asya", "Beyza",
        "Ceylan", "Dila", "Ezgi", "Gokce", "Hazal", "Iclal", "Kivilcim",
        "Lidya", "Mavi", "Nil", "Ruya", "Sude", "Tulay", "Yildiz"
    };
    static constexpr int count = sizeof(names) / sizeof(names[0]);

    Irand pick(0, count - 1);
    return names[pick()];
}

inline std::string random_surname() {
    static const char* surnames[] = {
        "Yilmaz", "Kaya", "Demir", "Sahin", "Celik", "Yildiz", "Yildirim",
        "Ozturk", "Aydin", "Ozdemir", "Arslan", "Dogan", "Kilic", "Aslan",
        "Cetin", "Kara", "Koc", "Kurt", "Ozkan", "Simsek", "Polat",
        "Korkmaz", "Cakir", "Erdogan", "Yavuz", "Ozer", "Turk", "Guler",
        "Sonmez", "Aksoy", "Bulut", "Gunes", "Kaplan", "Cinar", "Tekin",
        "Bozkurt", "Tas", "Aktas", "Bal", "Kaan", "Duran", "Cakmak",
        "Ates", "Gul", "Ekinci", "Uysal", "Erdem", "Sen", "Ergin",
        "Ozturk", "Turan", "Acar", "Aksu", "Bilgin", "Coskun", "Demirel",
        "Efe", "Gundogdu", "Hakan", "Isik", "Kahraman", "Karaca", "Kocak",
        "Mert", "Nalbant", "Ocak", "Pekmez", "Saglam", "Tuncel", "Ulusoy",
        "Vural", "Yalcin", "Zengin", "Akin", "Balci", "Cebeci", "Demirci"
    };
    static constexpr int count = sizeof(surnames) / sizeof(surnames[0]);

    Irand pick(0, count - 1);
    return surnames[pick()];
}

inline std::string random_fullname() {
    return random_name() + " " + random_surname();
}


template<typename Collection, typename Generator>
void rfill(Collection& c, std::size_t count, Generator gen)
{
    for (std::size_t i = 0; i < count; ++i) {
        if constexpr (requires { c.push_back(gen()); })
            c.push_back(gen());   // vector, list, deque...
        else
            c.insert(gen());      // set, unordered_set...
    }
}


