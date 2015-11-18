#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=entware-opt
PKG_VERSION:=222108
PKG_RELEASE:=2

include $(INCLUDE_DIR)/package.mk

define Package/entware-opt
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libc +libgcc +libstdcpp +libpthread +librt \
		+ldconfig +findutils +terminfo +USE_GLIBC:locales
	TITLE:=provides basic toolchain libraries (dummy)
	MAINTAINER:=Entware team, entware.wl500g.info, Zyxmon
endef

define Package/entware-opt/description
 entware-opt is a metapackage to install Entware basic libraries and scripts.
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
	$(INSTALL_DIR) $(1)/opt/usr/lib
endef

define Package/entware-opt/conffiles
/opt/etc/profile
endef

define Package/entware-opt/postinst
#!/bin/sh

echo -n "Updating /opt/etc/ld.so.cache... "
/opt/bin/ldconfig > /dev/null 2>&1
echo "done."
endef

$(eval $(call BuildPackage,entware-opt))
