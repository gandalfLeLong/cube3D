# cub3D

A project dedicated to creating a 3D graphical representation of a maze from a first-person perspective using the Raycasting technique. This project explores trigonometry, window management, and real-time environment rendering.

---

### 💡 Key Features
* **Raycasting Engine:** Simulates a 3D environment from a 2D map by calculating the distance between the player and the nearest walls.
* **Map Parsing:** Extracts data from `.cub` files, including texture paths, RGB floor/ceiling colors, and map layout validation.
* **Graphic Textures:** Implements wall textures (North, South, East, West) using XPM images for a realistic feel.
* **User Input:** Smooth movement (WASD) and camera rotation (Arrow keys) with event management through MiniLibX.
* **Performance:** Optimized with high-level flags (`-O3`, `-ffast-math`) for fluid rendering.

---

### 🛠️ Compilation & Usage

The Makefile handles the compilation of the project, including its dependencies (**Libft** and **MiniLibX**).

| Rule | Description |
| :--- | :--- |
| `make` | Compiles the `cub3D` executable. |
| `make debug` | Compiles with AddressSanitizer and debug symbols. |
| `make clean` | Removes object files and library build files. |
| `make fclean` | Performs a full cleanup (objects, libraries, and binaries). |
| `make re` | Recompiles the entire project from scratch. |

**To run the program:**
Launch the executable with a valid map file as an argument:
```bash
./cub3D maps/example.cub
