# Home server setup record

**Status:** Installed and running  
**Recorded:** 4 October 2026; status update 1 November 2026  

## Host hardware

| Item | Recorded value |
| --- | --- |
| Processor | AMD Ryzen 7 3700X |
| Memory | 32 GB DDR4 |
| Graphics | NVIDIA GTX 1080 |
| Cooling | Hybrid AIO cooler |
| System storage | About 460 GB internal storage reported; earlier setup notes describe a 450 GB M.2 drive. Exact capacity, health, interface, and remaining free space have not been reconciled or checked. |
| Motherboard | Not recorded |
| Idle power | Not measured |

The previous Windows installation was replaced by Proxmox VE. Whether any Windows files needed to be preserved or were backed up is not recorded.

## Proxmox host

- **Software:** Proxmox Virtual Environment 9.2.2, installed bare metal
- **Host name:** `proxmox`
- **Management address:** `192.168.2.50:8006` on the home LAN
- **VM storage:** `local-lvm` on the 450 GB M.2 drive
- **Network bridge:** `vmbr0`
- **CPU virtualization:** AMD SVM was enabled in BIOS/UEFI after the first VM start reported that KVM virtualization was unavailable.

The router's DHCP reservation status for the Proxmox host has not been confirmed.

## Home Assistant VM

- **VM ID/name:** 100 / `homeassistant`
- **Guest OS:** Home Assistant OS 18.3, KVM/QEMU image
- **State:** Running; initial onboarding complete
- **LAN address:** `192.168.2.202`
- **MAC address:** `BC-24-11-C4-71-04`
- **CPU:** 2 cores; model `x86-64-v2-AES`
- **Memory:** 4 GiB
- **Firmware/machine:** OVMF (UEFI), Q35
- **Secure Boot:** Pre-enrolled keys disabled
- **Disk controller:** VirtIO SCSI single; Home Assistant boot image is on `local-lvm`
- **Network:** VirtIO adapter on `vmbr0`; Proxmox firewall flag enabled on the adapter

The router reservation for the Home Assistant address has not been confirmed. Home Assistant was opened successfully at `homeassistant.local/onboarding.html`.

## Setup and troubleshooting notes

1. Proxmox initially reported that KVM virtualization was unavailable. Enabling AMD SVM in the motherboard firmware resolved that blocker.
2. The first Home Assistant VM attempt did not obtain an address. The VM had the original 4 MiB EFI variables disk attached as `scsi0`; this was mistaken for the imported Home Assistant disk. The Home Assistant image was the separate unused disk. The imported image was attached as the SCSI boot disk, after which Home Assistant booted and completed onboarding.
3. The VM CPU model is set to `x86-64-v2-AES`.

## Follow-up checks

- Add or verify router DHCP reservations for `192.168.2.50` and `192.168.2.202`.
- Configure Proxmox and Home Assistant backups to storage outside the M.2 system drive.
- Check M.2 health and measure the server's idle power.
- Identify the motherboard, exact M.2 protocol/size and occupied slots, free SATA ports/bays, and current free space before buying a 2 TB drive.
- A 2 TB drive is the near-term expansion target. It is not the final NAS or camera-recording capacity; defer those services until a larger storage design is affordable and backed up.
- Compare any Amazon UK Black Friday offer against a recorded baseline instead of treating the crossed-out price as a discount. Black Friday is Friday 27 November 2026; Amazon's UK sale window is not confirmed in this record.
- Record the motherboard model and review its BIOS settings/firmware version.
- Plan separate storage before adding camera recording.

Do not put passwords, recovery codes, or other credentials in this record.
