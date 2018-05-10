#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=urbackup-server
PKG_VERSION:=2.2.11
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://hndl.urbackup.org/Server/$(PKG_VERSION)
PKG_HASH:=164e1ea4f30d2b1f1b4b3ed66eece6aba40e10fd55d99215769dc88d3f1c0f58

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/urbackup-server
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libcurl +zlib +libstdcpp
	TITLE:=UrBackup Server
	URL:=http://www.urbackup.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/urbackup-server/description
 UrBackup is an easy to setup Open Source client/server backup system
endef

CONFIGURE_ARGS += \
	--enable-embedded-cryptopp \
	--oldincludedir="$(STAGING_DIR)/opt/include" \

define Package/urbackup-server/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/var/urbackup
	$(INSTALL_DIR) $(1)/opt/share/urbackup
	$(CP) $(PKG_INSTALL_DIR)/opt/share/urbackup/* $(1)/opt/share/urbackup/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S60urbackup-server $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,urbackup-server))
