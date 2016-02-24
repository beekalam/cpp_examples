//taken from http://msoucy.me
/*
Templates on unions (C++11)

Templates can be done on the types in a union as well:

template<typename From, typename To>
union union_cast {
    From from;
    To   to;

    union_cast(From from)
        :from(from) { }

    To getTo() const { return to; }
};

Type punning didn't stop being undefined, by the way.
*/

template<typename From, typename To>
union union_cast {
    From from;
    To   to;

    union_cast(From from)
        :from(from) { }

    To getTo() const { return to; }
};

int main() {

}