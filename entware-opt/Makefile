#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=entware-opt
PKG_VERSION:=1.0
PKG_RELEASE:=4

include $(INCLUDE_DIR)/package.mk

define Package/entware-opt
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libc +libgcc +libstdcpp +libpthread +librt \
		+busybox \
		+zoneinfo-asia +zoneinfo-europe \
		+findutils +terminfo +locales
	TITLE:=provides basic toolchain libraries (dummy)
	MAINTAINER:=Entware team, http://entware.net
	CONFLICTS:=opt-ndmsv2
endef

define Package/android-opt/description
 android-opt is a metapackage to install Entware-3x basic libraries and scripts
 on android devices.
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
	$(INSTALL_DATA) ./files/{shells.1,passwd.1,group.1,screenrc} $(1)/opt/etc
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


$(eval $(call BuildPackage,entware-opt))
