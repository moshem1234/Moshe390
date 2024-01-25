# Storage, Busses and Networking

## Erik Bobinsky, Ryan Connolly, and Moshe Moskowitz

> ### Group Project
>
> * Instead of test 2, prepare a document summarizing the following information
> * Groups up to 3 people
> * Anything from the internet must be cited
> * Use of chatgpt is encouraged, but you should rewrite it and make it your own
> * scalable graphics (svg, pdf) preferred

## Busses Definitions

> What is a bus? Explain it. Show diagrams.
You may use diagrams from the internet if cited. Your own, improved version will score higher.

* A bus is a connection between components and devices in a computer network (or connected to a computer) to communicate and transfer information. Similar to a transportation bus that makes stops picking up and dropping people off, hardware buses transmit data from one location or device to another ([computerhope.com](<https://www.computerhope.com/jargon/b/bus.htm>)).

![image](https://cdn.discordapp.com/attachments/1090042473864232970/1105567455058862101/bus_diagram_ss.png)

![image](https://i.ytimg.com/vi/alYwqzO6ZEQ/maxresdefault.jpg)  
([Youtube: TeachingCS](<https://www.youtube.com/watch?v=alYwqzO6ZEQ&ab_channel=TeachingCS>))

> Explain different busses shown below and the purpose of each

* __Data Bus:__
  * __Purpose:__ “A data bus is a system within a computer or device, consisting of a connector or set of wires, that provides transportation for data ([techopedia.com](https://www.techopedia.com/definition/6733/data-bus)).” It reads and writes all the data that is going into or out of the CPU.
  * __Wires:__ “The data Bus contains either 8, 16, 32, 64, 128 or more wires. Most home computer systems are 32 or 64 wires. In addition to the data wires, there is one or more additional wires used for signalling and control ([inetdaemon.com](https://www.inetdaemon.com/tutorials/computers/hardware/mainboards/bus/#:~:text=The%20data%20Bus%20contains%20either,used%20for%20signalling%20and%20control.)).”
  * __Speed:__ “A typical data bus is 32-bits wide. This means that up to 32 bits of data can travel through a data bus every second. Newer computers are making data buses that can handle 64-bit and even 96-bit data paths. At the same time they are making data buses to handle more bits, they are also making devices that can handle those higher bitrates ([easytechjunkie.com](https://www.easytechjunkie.com/what-is-a-data-bus.htm)).”
  * __Limitations:__ Using a data bus has many limitations that include bandwidth, distance, security, compatibility, and interference limitations, which cause slower data transfer rates, data loss and errors, security risks and compatibility issues. (ChatGPT, Rephrased)

* __Address Bus:__
  * __Purpose:__ “An internal channel that transmits the RAM location of the data being processed or the instruction being fetched ([pcmag.com](https://www.pcmag.com/encyclopedia/term/address-bus)).” It is used to send the addresses of the memory location(s) it wants to be read/written. (Only goes one direction)
  * __Wires:__ “In many older computers, the address bus was 16 bits wide (a = 16). This meant that there were 16 wires. Such microprocessors could address up to 216 = 65536 memory locations. By increasing the width of the address bus, more memory locations can be directly addressed. Each time the width is increased by one wire, the address capacity is doubled. ARM processors normally have 32-bit wide address buses. A 32-bit ARM processor could address up to 232 = 4,294,967,296 memory locations! ([www-mdp.eng.cam.ac.uk](http://www-mdp.eng.cam.ac.uk/web/library/enginfo/mdp_micro/lecture1/lecture1-3-4.html))”
  * __Speed:__ The speed of the address bus is usually in the range of 2-4 GHz for modern CPUs and relates to the system clock speed. (ChatGPT, Rephrased)
  * __Limitations:__ The limitations of the address bus include constraints on the maximum amount of memory that can be addressed, compatibility with the CPU and memory modules, and data transfer delays due to system clock speed and memory module access times. Additionally, any interference or noise on the address bus can lead to data errors or loss. (ChatGPT, Rephrased)

## Other PC busses

> What is the bus speed, how does it apportion bandwidth (lanes)?  
What is the cost for advancing to new generations?

* PCiE
  * current revision - 4.0
    * “PCIe Gen 4 operates at 16 GT/s, or around 2 GB/s (gigabytes per second) per PCIe lane”([kingston.com](<https://www.kingston.com/en/blog/pc-performance/pcie-gen-4-explained#:~:text=By%20comparison%2C%20PCIe%20Gen%204,per%20second)%20per%20PCIe%20lane.>)).
  * next - 5.0
    * “PCIe 5.0 has a bandwidth of 3.94 gigabytes per second for each lane. On a device with 16 lanes (like a GPU) that's roughly 63GB/s, and on a device with 4 lanes (like an SSD) that's about 16GB/s”([xda-developers.com](<https://www.xda-developers.com/pcie-5/#:~:text=PCIe%205.0%20has%20a%20bandwidth,)%20that%27s%20about%2016GB%2Fs.>))
  * 3.0 - still popular
    * “Speed costs money… The big tradeoff of the higher speeds is that signals won’t travel as far on existing designs… Retimer chips for a 16-lane full PCIe 4.0 could cost $15 to $25”([eetimes.com](<https://www.eetimes.com/costs-dog-pcie-speed-gains/>)).
  * ![image](https://media.fs.com/images/community/upload/wangEditor/201912/30/_1577696037_99zwUgQjV6.jpg) ([community.fs.com](<https://community.fs.com/blog/pcie-card-selection-guide.html>))

* USB
  * 3.2
    * “USB 3.2 identifies three transfer rates – 20Gbps, 10Gbps, and 5Gbps. Key characteristics of the USB 3.2 specification include: Defines multi-lane operation for new USB 3.2 hosts and devices, allowing for up to two lanes of 10Gbps operation to realize a 20Gbps data transfer rate, without sacrificing cable length”([usb.org](<https://www.usb.org/usb-32-0#:~:text=USB%203.2%20identifies%20three%20transfer,rate%2C%20without%20sacrificing%20cable%20length>))
  * 3.1
    * “USB 3.1 is the most recent version of the USB (Universal Serial Bus) standard for connecting computers and electronic devices. It is capable of data transfer speeds up to 10Gbps, and while it can use the USB-C connector type, it can also use a variety of other connector types.” ([startech.com](<https://www.startech.com/en-us/faq/usb-3-1-port-capabilities>))
  * 3.0
    * “USB 3.0 has transmission speeds of up to 5 Gbit/s or 5000 Mbit/s, about ten times faster than USB 2.0 (0.48 Gbit/s) even without considering that USB 3.0 is full duplex whereas USB 2.0 is half duplex. This gives USB 3.0 a potential total bidirectional bandwidth twenty times greater than USB 2.0.”([Wikipedia](<https://en.wikipedia.org/wiki/USB_3.0#:~:text=USB%203.0%20has%20transmission%20speeds,times%20greater%20than%20USB%202.0.>))
  * 2.0
    * “USB 2.0 offers a transfer rate of about 480 Mbps, whereas USB 3.0 offers a transfer rate of about 4,800 Mbps which is equal to about 5 GB.” ([usbmemorydirect.com](<https://www.usbmemorydirect.com/blog/usb-2-0-vs-3-0/#:~:text=Speed%20%2D%2D%20USB%202.0%20offers,equal%20to%20about%205%20GB.>))
  * 1.0
    * “1.5 megabits per second (Mbps) at low speed and 12 Mbps at full speed.” ([digikey.com](<https://www.digikey.com/en/articles/decoding-the-usb-standards-from-1-to-4#:~:text=USB%201.0%20marked%20the%20first,12%20Mbps%20at%20full%20speed.>))
  * ![image](https://www.etechnophiles.com/wp-content/uploads/2022/03/USB-ports-pinout_800x450.jpg) ([etechnophiles.com](<https://www.etechnophiles.com/usb-pinout-ports-connectors/>))

> Look up the security of USB

* USB connections have little to no security: “USB flash drives pose two major challenges to information system security: data leakage owing to their small size and ubiquity and system compromise through infections from computer viruses, malware and spyware.” ([Wikipedia](<https://en.wikipedia.org/wiki/USB_flash_drive_security#:~:text=3%20Remote%20management-,Major%20dangers%20of%20USB%20drives,computer%20viruses%2C%20malware%20and%20spyware.>))

## Embedded Systems Busses

1. CANBUS
    * “The Controller Area Network (CAN bus) is a message-based protocol designed to allow the Electronic Control Units (ECUs) found in today’s automobiles, as well as other devices, to communicate with each other in a reliable, priority-driven fashion ([dewesoft.com](<https://dewesoft.com/blog/what-is-can-bus>)).”
    * ![image](https://tekeye.uk/automotive/images/can-network.png) ([tekeye.uk](<https://tekeye.uk/automotive/can-bus-cable-wiring>))
1. OneWire
    * “1-Wire is a device communications bus system designed by Dallas Semiconductor that provides low-speed (16.3 kbit/s) data, signaling, and power over a single conductor.” ([Wikipedia](<https://en.wikipedia.org/wiki/1-Wire>))
    * ![image](https://www.analog.com/-/media/analog/en/landing-pages/technical-articles/1wire-communication-through-software--maxim-integrated/522fig01.gif?imgver=1) ([analog.com](<https://www.analog.com/en/technical-articles/1wire-communication-through-software.html>))
1. [I2C](<https://duckduckgo.com/?t=ffab&q=raspberry+pi+I2C&iax=images&ia=images>)
    * “The I2C bus was designed by Philips in the early ’80s to allow easy communication between components which reside on the same circuit board. Philips Semiconductors migrated to NXP in 2006. The name I2C translates into “Inter IC”. Sometimes the bus is called IIC or I²C bus.” ([i2c-bus.org](<https://www.i2c-bus.org/>))
    * ![image](https://electrosome.com/wp-content/uploads/2018/02/I2C-Interface.png) ([electrosome.com](<https://electrosome.com/i2c/>))
1. SPI
    * “A Serial Peripheral Interface (SPI) bus is a system for serial communication, which uses up to four conductors, commonly three. One conductor is used for data receiving, one for data sending, one for synchronization and one alternatively for selecting a device to communicate with. It is a full duplex connection, which means that the data is sent and received simultaneously. The maximum baud rate is higher than that in the I2C communication system.” ([tutorialspoint.com](<https://www.tutorialspoint.com/arduino/arduino_serial_peripheral_interface.htm>))
    ![image](https://www.corelis.com/wp-content/uploads/2017/05/1-11-1.jpg) ([corelis.com](<https://www.corelis.com/education/tutorials/spi-tutorial/>))

## Storage: Explain the following storage terms

> As usual, the more diagrams you have (particularly your own) the higher your group score
You should state for each kind of device, amount of storage  
Express also in $/GB, Gb/area

* Compare to human DNA. How much is a human genome?
  * One gram of DNA can store 215 petabytes of data. A petabyte is 1,024 terabytes. So one gram of DNA can store approximately 220,160 terabytes.
* Direct Memory Access (DMA) (hard drives) address bus can also be written by "smart devices"
  * Direct Memory Access (DMA) is used for high speed data transfer between peripheral devices and the main memory of a computer system. DMA itself is a technique and not a device, and thus is not related to the amount of storage in a system. Therefore, there is no direct conversion between DMA and storage capacity in terms of $/Gb or Gb/area, since the cost per Gb varies greatly depending on circumstances like type and capacity of storage, performance or manufacturer (Rewritten from Chat GPT). "However, in ISA bus standard, up to 16 MB of memory can be addressed for DMA, and EISA and Micro Channel Architecture standards allow access to the full range of memory addresses (given they are addressable with 32 bits)" ([techtarget.com](<https://www.techtarget.com/whatis/definition/Direct-Memory-Access-DMA>)).
  * ![image](https://open4tech.com/wp-content/uploads/2020/04/DMA_block_diagram-1.jpg) ([open4tech.com](<https://open4tech.com/direct-memory-access-dma-in-embedded-systems/>))
* Block-structured device (like a hard drive)
  * Block-structured device is a type of storage device that stores data in fixed blocks or sectors like hard disk drives. The amount of storage in a block-structure device varies greatly depending on the device and its capacity. Thus, the cost per Gb and Gb per area values cannot be definitively determined because of the varying types of block structures devices. However, the cost per Gb of storage generally decreases as the capacity of the device increases, and the storage density of a device generally increases as technology advances (Rewritten from Chat GPT).
* volatile storage/non-volatile storage
  * “Volatile storage is a type of computer memory that needs power to preserve stored data. If the computer is switched off, anything stored in the volatile memory is removed or deleted ([techopedia.com](<https://www.techopedia.com/definition/9966/volatile-storage>)).”
  * Non-volatile storage (data persists without power source) used in solid-state drives, memory cards, and USB flash drives. The memory is organized into memory cells which are connected in a grid pattern, and can store multiple bits per memory cell, resulting in high density storage and low cost per bit. (Rewritten from ChatGPT)
  * ![image](https://ars.els-cdn.com/content/image/3-s2.0-B9780128016305000037-f03-11-9780128016305.jpg) ([sciencedirect.com](<https://www.sciencedirect.com/topics/computer-science/volatile-memory>))
* RAM
  * Random access memory is used to temporarily store data that the CPU interacts with. Programs that the computer uses are loaded from storage devices such as a hard disk, into RAM. The CPU then reads and writes data from there as needed. RAM capacity is often a limiting factor in how many programs can be active simultaneously. (Rewritten from ChatGPT)
  * ![image](https://www.researchgate.net/profile/Hussein-Abdulkadhim/publication/328842382/figure/fig2/AS:691209131540485@1541808507576/Fig3-internal-structure-of-RAM.ppm) ([researchgate.net](<https://www.researchgate.net/figure/Fig3-internal-structure-of-RAM_fig2_328842382>))
* ROM
  * Unlike RAM, read-only memory namely cannot be altered, as it is used to store permanent data. While RAM is volatile memory, ROM is not, meaning that even when the computer is off and the ROM isn’t connected to a power source, it still retains its data. Due to this, ROM is typically used to store firmware, which is a type of software designed for hardware to operate properly. (Rewritten from ChatGPT)
  * ![image](https://www.researchgate.net/profile/Jouko-Vankka/publication/27515907/figure/fig36/AS:643201585131520@1530362616176/Block-diagram-of-the-ROM.png) ([researchgate.net](<https://www.researchgate.net/figure/Block-diagram-of-the-ROM_fig36_27515907>))
* NAND-flash
  * “NAND Flash is a type of non-volatile storage technology that does not require power to retain data. An everyday example would be a mobile phone, with the NAND Flash (or the memory chip as it’s sometimes called) being where data files such as photos, videos and music are stored on a microSD card. NAND flash chips are roughly the size of a fingernail and can retain huge amounts of data ([simms.co.uk](<https://www.simms.co.uk/tech-talk/understanding-nand-flash-technology/>)).”
  * ![image](https://www.iwavesystems.com/wp-content/uploads/2020/03/nand-flash-controller.png) ([iwavesystems.com](<https://www.iwavesystems.com/product/nand-flash-controller/>))
* M.2
  * Introduced as a replacement for the mSATA standard, M.2 is a form factor(refers to the size and dimensions of the component) for computer expansion cards, storage devices, and wireless networks adapters. They are rectangular and measure 22mm in width and 80mm in length, and are designed to be installed directly onto a motherboard. Recently, they have become increasingly popular as an ideal, small, and fast storage solution; it can be seen in high end computers(especially laptops) for high performance, especially for programs such as videogames, or for data centers. (Rewritten from ChatGPT)
  * ![image](https://www.delock.de/infothek/M.2/images/keys-b-m_engl.jpg) ([delock.de](<https://www.delock.de/infothek/M.2/M.2_e.html>))
* hard drive
  * __platter:__ “A platter is one or more aluminum, glass, or ceramic disk coated in a magnetic media is located within a hard drive to store all your computer's data permanently. When the computer is turned on, these platters begin to rotate at so many RPM (rotations per minute). This rate varies depending on the model of hard drive you have.” ([computerhope.com](<https://www.computerhope.com/jargon/p/platter.htm>))
  * __head:__ “The read/write heads in your hard disk drive are very tiny copper coils on the ends of long arms that function somewhat like the needle on a record player. These are responsible for creating all of the data on your hard drive by altering tiny magnetic regions on the hard disk platters and reading it back.” ([gillware.com](<https://www.gillware.com/hard-drive-data-recovery/hard-disk-heads-repair-readwrite-heads-failure-data-recovery/#:~:text=The%20read%2Fwrite%20heads%20in,platters%20and%20reading%20it%20back.>))
  * __sector:__ “A sector is a specifically sized division of a hard disk drive, optical disc, floppy disk, flash drive, or another kind of storage medium.” ([lifewire.com](<https://www.lifewire.com/what-is-a-sector-2626003>))
  * __track:__ “A disk drive track is a circular path on the surface of a disk or diskette on which information is magnetically recorded and from which recorded information is read.” ([wikiwand.com](<https://www.wikiwand.com/en/Track_(disk_drive)>))
  * __track-track seek time:__ “Seek time measures the delay for the disk head to reach the track.” ([courses.cs.washington.edu](<https://courses.cs.washington.edu/courses/cse378/10sp/lectures/lec26.pdf>))
  * ![image](https://cdn.britannica.com/63/74063-050-2714FB88/hard-drive.jpg) ([britannica.com](<https://www.britannica.com/technology/hard-disk>))
* tape drive
  * “A tape drive is a data storage device that reads and writes data on a magnetic tape. Magnetic-tape data storage is typically used for offline, archival data storage. Tape media generally has a favorable unit cost and a long archival stability.” ([Wikipedia](<https://en.wikipedia.org/wiki/Tape_drive>))
  * ![image](https://d3i71xaburhd42.cloudfront.net/8f4eba1861ca3bb2e521fb78639864c0c9b34d9a/2-Figure1-1.png) ([semanticscholar.org](<https://www.semanticscholar.org/paper/Innovations-in-the-Design-of-Magnetic-Tape-Harris-Phillips/8f4eba1861ca3bb2e521fb78639864c0c9b34d9a>))

| Speed Statistic    | HDD (Hard Disk Drive) | SSD (Solid State Drive) | NVMe m.2 (Nonvolatile Memory Express) |
|--------------------|-----------------------|-------------------------|---------------------------------------|
| Read Speed         | 80 MB/s               | 200MB/s                 | 5000 to 7300 MB/s                     |
| Write Speed        | 160 MB/s              | 550 MB/s                | 5000 to 6350 MB/s                     |
| Capacity Available | From 250GB to 14TB    | 250GB to 4TB            | 500GB to 4TB                          |
([tekie.com](<https://tekie.com/blog/hardware/ssd-vs-hdd-speed-lifespan-and-reliability/>))

## Memory Speed

### How fast is memory?

* __DDR4 RAM:__ “DDR4 speeds start at 2400 MT/s and offer faster speeds and responsiveness than all other generations of memory ([crucial.com](<https://www.crucial.com/support/memory-speeds-compatability#:~:text=DDR4%20speeds%20start%20at%202400,the%20most%20from%20their%20system.>)).”
* __DDR5 RAM:__ “DDR5 speeds begin at 4800MHz and range up to 7200MHz, with even higher speeds to come in the future ([pcgamer.com](<https://www.pcgamer.com/best-ddr5-ram-for-gaming-in-2022/>)).”
* __SSD:__ “On the other hand, a standard SATA SSD will provide a read/write speed of between 200 MB/s to 550 MB/s ([tekie.com](<https://tekie.com/blog/hardware/ssd-vs-hdd-speed-lifespan-and-reliability/#:~:text=On%20the%20other%20hand%2C%20a,speeds%20exceeding%205000%20MB%2Fs.&text=As%20noted%20above%2C%20an%20SSD,5x%20that%20of%20an%20HDD.>)).”
  * ![image](https://uwaterloo.ca/arts-computing-newsletter/sites/ca.arts-computing-newsletter/files/uploads/images/hard-drive-guide-ssd-diagram_1.jpg) ([uwaterloo.ca](<https://uwaterloo.ca/arts-computing-newsletter/winter-2018/feature/everything-you-need-know-about-solid-state-drives-ssd>))
* __Hard drive:__ explain the physics of how it works
  * A hard drive is a non-volatile storage device that stores data using magnetic recording technology. A hard drive consists of a spinning disk, read-write hands, actuator arm, and control electronics. The spinning disk is made of magnets which allow it to rotate at extremely high speeds (up to 15,000 revolutions per minute) and the read-write hands are mounted on the arm, which moves the heads across the surface of the disk to read or write data. Through the process of magnetic recording, the read-write hands use a magnetic field to change the polarity of tiny areas on the disk surface, which represent individual bits of digital data. The direction of the magnetic field determines the value of the bit (0 or 1), and the density of the magnetic areas determines the storage capacity on the disk (Rewritten from Chat GPT).

> Find examples like below, and compare at least one DDR4 RAM to DDR5 RAM
> <https://www.newegg.com/g-skill-32gb/p/N82E16820374446?Description=ddr5%20ram&cm_re=ddr5_ram-_-20-374-446-_-Product&quicklink=true>
>
> Timing 36-46-46-125
>
> <https://www.newegg.com/corsair-32gb-288-pin-ddr4-sdram/p/N82E16820236607?Description=ddr4&cm_re=ddr4-_-20-236-607-_-Product&quicklink=true>
>
> <https://en.wikipedia.org/wiki/DDR_SDRAM>

![image](https://i.imgur.com/RdAjHBp.png)
![image](https://i.imgur.com/RxGzxGe.png)
![image](https://i.imgur.com/AwVRS2i.png)  
([Newegg](<https://www.newegg.com/Product/Productcompare?CompareItemList=20-374-427%2C20-232-928&compareall=true>))

While DDR5 RAM is faster than DDR4 RAM, it does have a higher latency.

## Memory access

1. Reading the same memory is cached (fastest)
    * When the CPU reads the data from a memory location, the data is stored in a cache to speed up the following reads, which reduces the number of times the processor has to read from main memory. Reading the same memory location repeatedly is faster since the data is already present in the cache, and the processor can access it much more quickly (Rewritten from Chat GPT).
2. sequential is best
    * Sequential memory is also ideal since it allows the CPU to predict the next memory location and preload it, reducing access time.The CPU can take advantage of spatial locality, meaning that the data stored close together is likely to be accessed together. Thus, accessing nearby memory locations is the second-best option after sequential access (Rewritten from Chat GPT).
3. nearby is 2nd best
4. Jumping by more than burst mode is worse
    * When the CPU jumps out of the memory row, it disrupts the pattern of sequential memory access. This adds a significant amount of time as additional overhead is produced since the processor has to wait for the data to be obtained from memory. Accessing data from memory that is located far apart is also likely to result in additional overhead as the processor has to wait for the data to be fetched from secondary storage (Rewritten from Chat GPT).
5. Jumping out of the memory Row is even worse
6. extra credit if you discuss MMU and paging *Being out of memory and having to demand page memory is worst
    * To mitigate the effects of jumping, computer systems use memory management units (MMUs) and paging. The MMU maps virtual addresses to physical memory locations, which allows the processor to access data in main memory efficiently, and paging helps to reduce the effects of memory fragmentation by breaking down memory into smaller units called pages. When physical memory runs out, the system can page out less frequently used pages to secondary storage. However, when the system runs out of physical memory and has to demand page memory, the performance is the worst since accessing data from secondary storage is much slower compared to accessing data from main memory. This can result in a significant slowdown in the system's performance (ChatCPT).

## Networking

> Create a table summarizing the kinds of wired and wireless network common today.  
You can include 10Gb which is not exactly common, but you don't have to include exotic hardware only used in high-end machine rooms

### Wireless

| Generation | IEEE standard | Adopted | Maximum link rate (Mbit/s) | Radio frequency (GHz) |
|:----------:|:-------------:|:-------:|:--------------------------:|:---------------------:|
|   Wi-Fi 7  | 802.11be      | (2024)  | 1376 to 46120              | 2.4/5/6               |
|  Wi-Fi 6E  | 802.11ax      | 2020    | 574 to 9608                | 6                     |
|   Wi-Fi 6  | 802.11ax      | 2019    | 574 to 9608                | 2.4/5                 |
|   Wi-Fi 5  | 802.11ac      | 2014    | 433 to 6933                | 5                     |
|   Wi-Fi 4  | 802.11n       | 2008    | 72 to 600                  | 2.4/5                 |
| (Wi-Fi 3)* | 802.11g       | 2003    | 6 to 54                    | 2.4                   |
| (Wi-Fi 2)* | 802.11a       | 1999    | 6 to 54                    | 5                     |
| (Wi-Fi 1)* | 802.11b       | 1999    | 1 to 11                    | 2.4                   |
| (Wi-Fi 0)* | 802.11        | 1997    | 1 to 2                     | 2.4                   |
([Wikipedia](<https://en.wikipedia.org/wiki/IEEE_802.11>))

### Wired

| Category | Speed            | Frequency |
|----------|------------------|-----------|
| CAT 1    | Carry only voice | 1MHz      |
| CAT 2    | 4Mbps            | 4MHz      |
| CAT 3    | 10Mbps           | 16Mhz     |
| CAT 4    | 16Mbps           | 20Mhz     |
| CAT 5    | 100Mbps          | 100Mhz    |
| CAT 5e   | 1000Mbps         | 100Mhz    |
| CAT 6    | 1000Mbps         | 250MHz    |
| CAT 7    | 10Gbps           | 600MHz    |
| CAT 7a   | 10Gbps           | 1000MHz   |
| CAT 8    | 25Gbps           | 2000Mhz   |
([learnabhi.com](<https://www.learnabhi.com/ethernet-cable-categories-cat1-cat2-cat3-cat4-cat5-cat5e-cat6-cat7-cat8/>))

> Compare methods of encryption and explain any vulnerabilities you find

![image](https://cdn.ttgtmedia.com/rms/onlineimages/networking-wireless_security_cheat_sheet-f.png)  
([techtarget.com](<https://www.techtarget.com/searchnetworking/feature/Wireless-encryption-basics-Understanding-WEP-WPA-and-WPA2>))

* Report how fast networking can get. You will be very impressed.
  * What's the fastest we can buy for "normal" money
    * 10 Gbps
  * What's the fastest used in industry
    * 400 Gbps
  * What's the fastest in research labs
    * 46 Tbps

> 1. Wifi
>     1. 802.11b  -  11Mb/s  -  WEP encryption
>     2. 802.11a
>     3. 802.11ax
>     4. 802.11ac     WPA2  (attacks possible on setup)
> 1. Ethernet 802.3
>     1. 10Mb/s   10BaseT (coax)
>     2. 100Mb/s   RJ-45
>     3. 1000Mb/s
>     4. 10Gb/s  expensive, runs hot
>     5. 2.5Gb/s

<!---->
> Find out what the world record is for high speed optical transmission

* “Technically, it's not the fastest data transmission rate ever – that honor belongs to a recent optical chip that clocked a staggering 1.84 petabits per second ([newatlas.com](<https://newatlas.com/telecommunications/data-transmission-fiber-optics-speed-record/#:~:text=Technically%2C%20it%27s%20not%20the%20fastest,staggering%201.84%20petabits%20per%20second.>)).”
