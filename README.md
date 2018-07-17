# AbstractVM

AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What you need to run this project is C++11

### Installing

To install you'll have to clone the project to your local machine

Step 1: Clone the project
```
git clone https://github.com/amatshiye/Abstract_VM
```
Step 2: Go inside the cloned repo
```
cd Abstract_VM
```

Step 3: Compile the project
```
make
```

To recompile the project use this command:
```
make re
```

## Running the tests

There are two ways to test the program. Either you pass a file to the program or you use the default mode (STDIN) to test it.

### Break down into end to end tests

To use the default mode follow these instructions:

Step 1: Run the program

```
./avm (With no arguments or else it will fail)
```

Step 2: Input instructions

for example:
```
push int8(100)
push int32(20)
dump
add
exit;; (Add the double semi-colon and press enter to execute your instructions)
```


### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc
