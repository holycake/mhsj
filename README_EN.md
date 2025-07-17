# Magic Century (MHSJ)

A text-based MUD game server with a Journey to the West theme, built on the FluffOS 2019 driver (UTF-8 encoding).

> ⚠️ This project is ported from the original GB2312-encoded Magic Century library, with extensive manual fixes and debugging, now running stably.

---

## Multi-language Instructions
- [中文版 README](README.md)
- [English README](README_EN.md)

---
## 📦 Getting Started

- **Driver Version**: `fluffos 20240714-4a59909c-4a6fafb5`
- **Recommendation**: Download and build the latest version from the [FluffOS official repository](https://github.com/fluffos/fluffos)
- **Startup Command**:

```bash
driver.exe config.ini
```

---

## 🖥️ Recommended Client

- Use [Mudlet 4.19.1](https://www.mudlet.org/) for the best connection experience.

---

## ⚠️ Known Issues

During the game's auto-save process, you may encounter the following warning:

```
save_svalue: unknown type 64 ignored.
```

The cause is unknown, likely due to invalid data formats in saved objects, but **this does not affect gameplay**.

---

## ✅ Completed Compatibility and Feature Fixes

### System and Architecture

- Fixed numerous compatibility issues from migrating from MudOS to FluffOS 2019.
- Added support for UTF-8 encoding, compatible with modern editors and terminals.

### Gameplay Adjustments

1. **Initial Age Modification**
   - Players start at age 8 upon character creation.
   - Modified files:
     - `/adm/daemons/logind.c`: Sets initial age.
     - `/obj/user.c`: Adjusts `update_age()` baseline.

2. **Skill Learning Mechanism**
   - In `/cmds/std/learn` and `study` commands, skills cannot be leveled beyond **combat experience / 550**.

3. **Map and Interaction Changes**
   - **New Area: Ming Dynasty Nanjing City**
     - Restored based on historical maps for immersive gameplay.
   - **Enhanced Interaction with Inn Waiter in Chang'an**
     - Players must provide a water container.
     - Pay `1 silver` to fill the container with osmanthus wine.

4. **Character Description System**
   - Detailed body type and appearance descriptions.
   - Supports granular descriptions based on gender, body type, and appearance value.

5. **Moon Palace and Ancient Tomb Adjustments**
   - **Optimized Rewards for Lotus Picking, Tree Chopping, and Tree Climbing**
     - Lotus picking: Can raise basic and special skills to **level 200**.
     - Tree chopping/climbing: Can raise skills to **level 150**.
   - **Retry Mechanism for Chi Meng's Apprenticeship**
     - If players fail and fall into the lake, they can retry apprenticeship.
   - **Xuanyuan Tomb: Human Head and Wooden Dummy Training**
     - Adjusted to be more logical and playable.

---

## 🧩 Additional Notes

- This project is for learning and sharing purposes, recommended for private server deployment.
- No further updates or maintenance will be provided for this MUD library.

---

## 🔗 Related Resources

- FluffOS Driver: [https://github.com/fluffos/fluffos](https://github.com/fluffos/fluffos)
- Mudlet Client: [https://www.mudlet.org](https://www.mudlet.org)

---

> Maintainer: HolyCake  
> Last Updated: July 2025
