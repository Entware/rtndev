#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=i2pd
PKG_VERSION:=2.15
PKG_REV:=d6253b1dee9bd0965eaf24577e79f9b87bfd6c7f
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/orignal/i2pd
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/i2pd
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libopenssl +boost-filesystem +boost-program_options +boost-date_time +libatomic
	TITLE:=simplified C++ implementation of I2P client
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/i2pd/description
 i2p router for Linux written on C++.
endef

TARGET_LDFLAGS += -latomic

define Package/i2pd/conffiles
/opt/etc/i2pd.conf
/opt/etc/i2pd_tunnels.conf
/opt/var/lib/i2pd/subscription.txt
endef

define Package/i2pd/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/i2pd $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/contrib/i2pd.conf $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/contrib/tunnels.conf \
		$(1)/opt/etc/i2pd_tunnels.conf
	$(INSTALL_BIN) ./files/S30i2p $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/var/lib/i2pd
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/contrib/subscriptions.txt \
		$(1)/opt/var/lib/i2pd
	$(CP) $(PKG_BUILD_DIR)/contrib/certificates \
		$(1)/opt/var/lib/i2pd
endef

define Package/i2pd/postinst
#!/bin/sh

[ -f /opt/etc/i2p.conf ] || exit 0
echo 'Please note: new path of configuration file is /opt/etc/i2pd.conf'
echo 'You may check /opt/etc/i2p.conf for custom options and delete it as obsolete.'
endef

$(eval $(call BuildPackage,i2pd))
