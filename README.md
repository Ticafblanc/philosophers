# 42 Philosopher Project

A solution to the classic dining philosophers problem as introduced in the 42 school curriculum.

## Table of Contents

- [Problem Overview](#problem-overview)
- [Installation](#installation)
- [Usage](#usage)
- [Technologies and Concepts Used](#technologies-and-concepts-used)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Problem Overview

The dining philosophers problem is a classic synchronization problem. It involves five philosophers sitting at a round table doing one of two things: thinking or eating. Between each philosopher, there's a fork. A philosopher needs both forks at their immediate left and right to eat. The challenge is to ensure that the philosophers won't starve and avoid race conditions and deadlocks.

## Installation

```bash
git clone https://github.com/[your_username]/42_philosopher.git
cd 42_philosopher
make
```

## Usage

Once compiled, run the program with:

```bash
./philo [number of philosophers] [time to die] [time to eat] [time to sleep] (optional: [number of times each philosopher must eat])
```

## Technologies and Concepts Used

- **Threading**: Using threads to simulate the parallel actions of the philosophers.
- **Mutex**: To avoid race conditions when picking up and putting down the forks.
- **Synchronization**: Making sure philosophers can eat and think without blocking each other.

## Contributing

All contributions are welcomed. If you have suggestions for improvements, please:

1. Fork the project.
2. Create your feature branch (`git checkout -b feature/featureName`).
3. Commit your changes (`git commit -m 'Add featureName'`).
4. Push to the branch (`git push origin feature/featureName`).
5. Open a Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contact

For any questions or feedback, reach out to me on [GitHub profil](https://github.com/Ticafblanc)

