# Burst
#### Personnal Project
#### Started in August 2020 - Ongoing

I started this library because of the needs I have with my engine Candle. The ECS module that I put into the code in the first place was my first attempt at writing such code, so it is, obviously, really inefficient.
With this library, I will try to fix the main issues I had with my previous implementation:
- The entities should be just an ID and they sould not own/keep track of their components,
- The components of the same type should be stored next to one another in order to improve performance (avoid cache misses),
- Only a limited number of components would be used,
- Using dynamic storage instead of pre-allocating a big chunk of memory in the first place.

**Disclaimer:** The goal of this library is not to be as efficient nor feature complete as others ([ENTT](https://github.com/skypjack/entt) for example), but rather fit my needs and allow me to learn how a proper ECS should be designed.

---
#### Ressources:
- [Data-Oriented Design](https://www.dataorienteddesign.com/dodbook/) by Richard Fabian,
- [The Cherno](https://www.youtube.com/c/TheChernoProject/videos) by Yan Chernikov,
- [Rez Bot](https://www.youtube.com/user/rezination/videos) by Rez Graham, and especially he's series on ECS design ([here](https://www.youtube.com/watch?v=5KugyHKsXLQ&list=PLUUXnYtS5hcVFwd4Z794vA-HsoF2OIWlR)),
- [Data-Oriented Design in C++](https://www.youtube.com/watch?v=rX0ItVEVjHc) by Mike Acton,
- [Is there more to game architecture than an ECS ?](https://www.youtube.com/watch?v=JxI3Eu5DPwE) by Bob Nystorm,
- [Bitsquid blog](http://bitsquid.blogspot.com/) and espcially [this series of article](http://bitsquid.blogspot.com/2014/08/building-data-oriented-entity-system.html)
