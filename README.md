# super-secure-cryptlib
As the name implies, super secure cryptography library, or function really?
Maybe one day ill find out how to make packages
## how does it work?
It has a `sushash()` function which blends anything into an integer, the original string is unrecoverable, even if you have the seed, except through brute force.
With this sushash function you can combine a key and data in a reversible manner - this is what `susencrypt()` does using an xor.
## neat knowledge
- Use the correct bit version or theres undefined behaviour
- Make sure the seed is an unsigned integer with the right bits
- The output of encrypting is a string-form hex
- the output of decrypting is a string
- the output of hashing is an ULL
- dont trust my code comments
