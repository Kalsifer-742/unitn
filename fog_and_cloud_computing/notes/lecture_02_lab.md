# Lecture 06/03/24

## Repeatable and Portable Environments

It works on my machine should only be a meme

- working in team
- environment to your needs
- isolate environments
- easy automation (workflows)
- productivity goes brrr

### Tools

- Git
- Vagrant
  - repeatable environments. list of instructions. similar to ansible in concept
  - relays on virtualbox
- Virtualbox
- Openssh

## Vagrant

takes as input a vagrant file, a description of the environment.

Takes an image like docker

Merge vagrant file and image to create what we want.

To do that vagrant uses providers(virtualbox ecc...) and provisioners(shell scripts, ansible)

vagrant obv is cli only.

## Exercise 03 gitlab

## Exercise 04 gitlab

## Configuration management system: CM

### Ansible

Tools for configuration. Configuration in a human readable format. Declarative style.

## Infrastructure as Code: IaC

Look at how socks proxy works and tunnels ecc...