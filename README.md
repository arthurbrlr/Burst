# Burst
#### Personnal Project
#### Started in August 2020 - Ongoing

I started this library because of the needs I have with my engine Candle. The ECS module that I put into the code in the first place was my first attempt at writing such code, so it is, obviously, really inefficient.
With this library , I will try to fix the main issues I had with my previous module, such as:
- Entities should be just an ID and they sould not own their components,
- Components of the same type should be stored next to one another in order to improve performance (avoid cache misses).

**Disclaimer:** The goal of this library is not to be as efficient nor feature complete as other ([ENTT](https://github.com/skypjack/entt) for example), but rather fit my needs and allow me to learn how a proper ECS should be designed.

---
#### Ressources:
- [Data-Oriented Design](https://www.dataorienteddesign.com/dodbook/) by Richard Fabian
- [The Cherno](https://www.youtube.com/c/TheChernoProject/videos) by Yan Chernikov
- [Rez Bot](https://www.youtube.com/user/rezination/videos) by Rez Graham, and especially he's series on ECS design ([here](https://www.youtube.com/watch?v=5KugyHKsXLQ&list=PLUUXnYtS5hcVFwd4Z794vA-HsoF2OIWlR))
