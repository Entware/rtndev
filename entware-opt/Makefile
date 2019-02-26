#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=entware-opt
# for historical reasons the first version was 222107 - that is glibc 2.22 & uclibc-ng 1.07
# we keep this numbering to upgrade package if needed.
# current version is 227000 - that is glibc 2.27 (or smaller) and no uclibc-ng
PKG_VERSION:=227000
PKG_RELEASE:=3

include $(INCLUDE_DIR)/package.mk

define Package/entware-opt
	SECTION:=base
	CATEGORY:=Base system
	DEPENDS:=+libc +libgcc +libstdcpp +libpthread +librt \
		+entware-release \
		+zoneinfo-asia +zoneinfo-europe \
		+findutils +terminfo +locales +opkg \
		+entware-upgrade
	TITLE:=provides basic toolchain libraries (dummy)
	MAINTAINER:=Entware team, https://entware.net
	CONFLICTS:=opt-ndmsv2
	PKGARCH:=all
endef

define Package/entware-opt/description
 entware-opt is a metapackage to install Entware basic libraries and scripts
endef

define Build/Prepare
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/entware-opt/install
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/rc.unslung $(1)/opt/etc/init.d/
	$(INSTALL_BIN) ./files/profile $(1)/opt/etc/
	$(INSTALL_DATA) ./files/rc.func $(1)/opt/etc/init.d/
	touch $(1)/opt/etc/ld.so.conf
	$(INSTALL_DATA) ./files/{shells.1,passwd.1,group.1} $(1)/opt/etc
	$(INSTALL_DIR) $(1)/opt/home $(1)/opt/root $(1)/opt/etc/skel
	$(INSTALL_DATA) ./files/.profile $(1)/opt/etc/skel
	$(INSTALL_DATA) ./files/.profile $(1)/opt/root
	$(INSTALL_DATA) ./files/.inputrc $(1)/opt/etc/skel
	$(INSTALL_DATA) ./files/.inputrc $(1)/opt/root
	$(INSTALL_DIR) $(1)/opt/{bin,sbin,lib/opkg,share,tmp,usr} \
	    $(1)/opt/var/{log,lock,run}
endef

define Package/entware-opt/conffiles
/opt/etc/profile
/opt/etc/passwd.1
/opt/etc/group.1
/opt/etc/shells.1
endef

# make symbolic links if busybox is not installed (standard=generic install)
define Package/entware-opt/postinst
#!/bin/sh

if [ -e /opt/bin/busybox ]; then
    exit 0
fi
if [[ -f /sbin/ifconfig && ! -f /opt/sbin/ifconfig ]]; then
    ln -s /sbin/ifconfig /opt/sbin/ifconfig
fi
if [[ -f /sbin/route && ! -f /opt/sbin/route ]]; then
    ln -s /sbin/route /opt/sbin/route
fi
if [[ -f /sbin/ip && ! -f /opt/sbin/ip ]]; then
    ln -s /sbin/ip /opt/sbin/ip
fi
if [[ -f /bin/netstat && ! -f /opt/bin/netstat ]]; then
    ln -s /bin/netstat /opt/bin/netstat
fi
if [[ ! -f /opt/bin/sh ]]; then
    ln -s /bin/sh /opt/bin/sh
fi
if [[ ! -f /opt/bin/ash ]]; then
    ln -s /bin/ash /opt/bin/ash
fi
endef




$(eval $(call BuildPackage,entware-opt))
