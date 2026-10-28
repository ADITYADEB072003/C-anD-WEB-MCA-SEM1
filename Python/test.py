import time
import torch
import torch.nn as nn

# GPU
device = torch.device("mps" if torch.backends.mps.is_available() else "cpu")
print("Device:", device)

# Heavy model
model = nn.Sequential(
    nn.Linear(4096, 8192),
    nn.ReLU(),
    nn.Linear(8192, 8192),
    nn.ReLU(),
    nn.Linear(8192, 8192),
    nn.ReLU(),
    nn.Linear(8192, 4096),
    nn.ReLU(),
    nn.Linear(4096, 10)
).to(device)

# Start smaller for 8 GB
batch_size = 512

x = torch.randn(batch_size, 4096, device=device)
y = torch.randint(0, 10, (batch_size,), device=device)

loss_fn = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(model.parameters())

# Warm-up
print("Warming up...")

for _ in range(5):
    optimizer.zero_grad()
    output = model(x)
    loss = loss_fn(output, y)
    loss.backward()
    optimizer.step()

if device.type == "mps":
    torch.mps.synchronize()

# Benchmark
print("\n🔥 Starting benchmark...")
start = time.time()

for i in range(100):

    optimizer.zero_grad()

    output = model(x)

    loss = loss_fn(output, y)

    loss.backward()

    optimizer.step()

    if device.type == "mps":
        torch.mps.synchronize()

    if (i + 1) % 10 == 0:
        print(f"{i + 1}/100 iterations")

total = time.time() - start

print("\n====================")
print("BENCHMARK COMPLETE")
print("====================")
print("Total time:", round(total, 2), "seconds")
print("Per iteration:", round(total / 100, 3), "seconds")