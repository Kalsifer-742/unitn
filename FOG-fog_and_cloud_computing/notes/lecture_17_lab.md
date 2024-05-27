# Lecture 3/5/24

# Topic: Lab07 (Kubernetes 2)

## Object Model

### Deployment

- declarative updates to `pods` and `replicasets`
- managed by DeploymentController
- on top of `ReplicaSets`, they provide the recording feature
  - if something goes wrong, we can rollback to a previously known state
- when something change a new replica set is created and when it's ready we switch to that. if something goes wrong we can do a rollback

## Selectors

- Labels
  - key-value pairs that can be attached to any object
  - they are used to organize and group
    - `app=webserver`, `app=database`, `env=dev`, `env=prod`

With selectors we can select only some pods, ex: `env==dev`

## Secrets

- ConfigMap API
- Secret API

ConfigMaps and Secrets are stored safely in the Kubernetes environment. Both ConfigMaps and Secrets can be created and retrieved in different ways

- Created from literal values, from files and from directory of files...
- Used via ENV_VARS, Volumes...

## Networking

Each Pod gets a unique IP.

Container Network Interface (CNI), proposed
by CoreOS and used by k8s.

IP assignment is offloaded to CNI

K8n forbid NAT in pod-to-pod communication. We achieve this using Software defined networking that implements a CNI. ex: Flannel

### Flannel

Uses UDP encapsulation

### External World communication

We use the Service and kube-proxy resources together. Good image at slide 24 of lab_07.

> "Service" is an high-level abstraction, which logically groups Pods and add policies to access them. This grouping is achieved via Labels and Selectors.

We use services because if I'm communication with a pod and it dies I'm not sure of the IP of the new pod

A Service is an higher-level abstraction which

- Logically groups Pods (Labels)
- Provide a policy to access them (Selectors)
- Set persistent endpoints for Pods
- Allow dynamic and automatic DNS
- Allow service `discovery`

more info: Slide 27-20 lab_07

tl;dr

> lot if internal stuff happening to make it all work like magic