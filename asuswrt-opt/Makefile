#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# This is the same package as entware-opt, it does not install busybox. It makes several symlinks instead of it!
# /opt/... folder order in /opt/etc/profile is different, /opt folders are the last in PATH
# This package is a replacement of entware-opt for asuswrt firmware


include $(TOPDIR)/rules.mk

PKG_NAME:=asuswrt-opt
PKG_VERSION:=1.0
PKG_RELEASE:=4

include $(INCLUDE_DIR)/package.mk

define Package/asuswrt-opt
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libc +libgcc +libstdcpp +libpthread +librt \
		+zoneinfo-asia +zoneinfo-europe \
		+findutils +terminfo +locales
	TITLE:=provides basic toolchain libraries (dummy)
	MAINTAINER:=Entware team, http://entware.net
	CONFLICTS:=opt-ndmsv2 entware-opt
endef

define Package/asuswrt-opt/description
 asuswrt-opt is a metapackage to install Entware-3x basic libraries and scripts
endef

define Build/Prepare
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/asuswrt-opt/install
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/rc.unslung $(1)/opt/etc/init.d/
	$(INSTALL_BIN) ./files/profile $(1)/opt/etc/
	$(INSTALL_DATA) ./files/rc.func $(1)/opt/etc/init.d/
	touch $(1)/opt/etc/ld.so.conf
	$(INSTALL_DATA) ./files/{shells.1,passwd.1,group.1,screenrc} $(1)/opt/etc
	$(INSTALL_DIR) $(1)/opt/home $(1)/opt/root $(1)/opt/etc/skel
	$(INSTALL_DATA) ./files/.profile $(1)/opt/etc/skel
	$(INSTALL_DATA) ./files/.profile $(1)/opt/root
	$(INSTALL_DATA) ./files/.inputrc $(1)/opt/etc/skel
	$(INSTALL_DATA) ./files/.inputrc $(1)/opt/root
	$(INSTALL_DIR) $(1)/opt/{bin,sbin,lib/opkg,share,tmp,usr} \
	    $(1)/opt/var/{log,lock,run}
endef

define Package/asuswrt-opt/conffiles
/opt/etc/profile
/opt/etc/passwd.1
/opt/etc/group.1
/opt/etc/shells.1
endef

define Package/asuswrt-opt/postinst
#!/bin/sh
ln -s /sbin/ifconfig /opt/sbin/ifconfig
ln -s /sbin/route /opt/sbin/route
ln -s /sbin/ip /opt/sbin/ip
ln -s /bin/netstat /opt/bin/netstat
ln -s /bin/sh /opt/bin/sh
ln -s /bin/ash /opt/bin/ash
endef

$(eval $(call BuildPackage,asuswrt-opt))
