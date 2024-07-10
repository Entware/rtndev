# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=urbackup-server
PKG_VERSION:=2.5.33
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:= \
	http://hndl.urbackup.org/Server/$(PKG_VERSION) \
	https://www.urbackup.org/downloads/Server/$(PKG_VERSION)
PKG_HASH:=65d7dab4d5178849c1ecc45b592143df066c641fd782d5a6448aa606561d7cff

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/urbackup-server
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libcurl +zlib +libstdcpp +zstd
	TITLE:=UrBackup Server
	URL:=http://www.urbackup.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/urbackup-server/description
 UrBackup is an easy to setup Open Source client/server backup system.
endef

CONFIGURE_ARGS += \
	--enable-embedded-cryptopp \
	--oldincludedir="$(STAGING_DIR)/opt/include"

TARGET_LDFLAGS += -lssp

define Package/urbackup-server/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/var/urbackup
	$(INSTALL_DIR) $(1)/opt/share/urbackup
	$(CP) $(PKG_INSTALL_DIR)/opt/share/urbackup/* $(1)/opt/share/urbackup
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S60urbackup-server $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,urbackup-server))
