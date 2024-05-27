# Lecture 06/03/24

## Reinforcment Learning

Learn to play games

an agent learns from the environment by interacting with it and
receiving rewards for performing actions

> if we have enough data we can also do:

### semi-supervised

### active learning

## Data collection

### Batch or Offline

- model learn from entire data set
- new model has to be retrained with new data to improve
- dataset is not too huge

### Online

- model learns from new data
- model adapts to changes
- data processed in real time and computational resources are limited

## Classification part 2

Why it all works? It's tanks to generalization
Generalization is key. A model needs to be able to do that.
Example:

| label | features |
| --- | --- |
_apple_ | **red** - **round** - leaf - 3oz,
_apple_ | green - **round** - **no leaf** - **4oz**

test: **red**, **round**, **no leaf**, **4oz** -> _apple_

### Probabilistic distribution

Generalization works because we take for granted that the training data has the same distribution of the test data.

They need to have the same distribution.

### Evaluation function

we need to find a function that can objectively evaluate our model. See how much correct it is ecc...

### Classification

Mathematical formalization

f(x) -> y {l1,l2,l3,l4,l5}

x are the inputs
y are the labels

f connects the two

### Density estimation

This is a type of unsupervised learning

Clustering

### Data and samples

Really important to train a correct and good model

We need to generate data with a correct distribution to conduct our training

### Model

polynomial curve fitting

i cannot search all functions so i reduce my space

for functions it could mean to reduce the maximum grade of a function

> typical question: what is the hypothesis space ? can you give me an example ?

### Ideal target

f* is the objective. what i would achieve if i could search all the space

I search f only on my hypothesis space. In the end we get an approximation and not a perfect function.

We are cheaping out on the training set. a larger training set will get us closer to the ideal target.

The real distribution is different to achieve but we can do better by enlarging our training set.


### Error function

example: we can calculate the distance between the points in the real function and our prediction. This way we created an error function.

2 PDF - Slide 39 example for curve fitting. Passing from the abstract values to the actual problem.

Find the arguments/weights that minimize the distance from the prediction and the actual function.

Typical errors: finding the local minimum and not the global minimum

Overgeneralization explained in the slides

I divide by n in the formula because i'm interested in the mean. I want to reduce the error on average.

### Mentions of

Typical question at the exam

- underfitting
- overfitting