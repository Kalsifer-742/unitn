# Lecture 12/04/24

# Topic: Lab06 (Kubernetes 1)

## Kubernetes aka k8s

_Kubernetes is an open-source
system for automating deployment, scaling, and
management of containerized applications_

### Architecture

- Multi node
  - node can be everything: bare metal, VM, ecc...

#### Master node

Manage the cluster. There can be more than one master node to achieve high availability. In this case there is a master which is the leader.

Accessible by:

- CLI
- GUI
- API

##### Components

- API server
- Scheduler
  - schedules work to the different worker nodes. It has information about the resource usage of each worker. When scheduling it takes into account if the worker has the correct requirements
    - data locality
    - affinity
  - ex: `disk == ssd`
- Controller manager
  - regulates the state of the cluster. It knows about the desired state and the current state(thanks to the API server). It take steps to achieve the desired state.
- etcd
  - distributed key-value storage. can be part of the master or be external.
  - it uses a consensus algorithm. at any moment one machine is the master and the others are followers.
  
#### Worker node

It runs the application in pods.

_A Pod is the scheduling unit in Kubernetes: a logical collection of one or more containers which are always scheduled together_

To access the application we normally connect directly to the worker and not the master.

##### Components

- Container runtime
  - default is docker
- kubelet
  - a service which communicates with the master node.
  - it receives the pods definition and runs the relative containers
  - it control the health of the pods
- kube proxy
  - we do not connect directly to pods
  - we use a logical construct called Service as a connection endpoint
    - A Service groups related Pods, which it load balances when accessed. kube-proxy is the network proxy which runs on each Worker Node and listens to the API Server
    - For each Service endpoint, kube-proxy sets up the routes so that it can reach to it

### Object Model

Model used by k8s to represent the state of the cluster

- entities
- policies
- ecc...

Object definitions is a `.yaml` file which describes for example a pod. The file is then translated to a `JSON` payload and sent to the server.

### Pods

They are very simple and not able to do a lot by themselves. Se use controllers to manage them.

- Deployments
  - high level concept. it includes also additional configurations(internet connectivity of the pods).(internally they often use replicasets)
- ReplicaSets
  - low level concept. it just insures that the correct number of replicas are running.