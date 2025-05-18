# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=oscam
PKG_REV:=76c92a2cb745fc32341bb4f43edd221cec5471e1
PKG_VERSION:=2.25.05
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://git.streamboard.tv/common/oscam.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=b64a56d2ae1ff3979874deb34b864734280bd665479a30fb375f5de46a79463e

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/oscam
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libpcsclite +libopenssl
	TITLE:=CAM software
	URL:=http://www.streamboard.tv/oscam/wiki
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/oscam/description
 OSCam is an Open Source Conditional Access Module software, based on the very
 good MpCS version 0.9d.
endef

define Package/oscam/conffiles
/opt/etc/oscam/
endef

CMAKE_OPTIONS += \
	-DCS_CONFDIR=/opt/etc/oscam \
	-DLIBUSBDIR=$(STAGING_DIR)/opt \
	-DOPTIONAL_INCLUDE_DIR=$(STAGING_DIR)/opt/include \
	-DOPTIONAL_LINK_DIR=$(STAGING_DIR)/opt/lib \
	-DOPENSSL_INCLUDE_DIR=$(STAGING_DIR)/opt/include \
	-DWITH_SSL=1 \
	-DHAVE_LIBCRYPTO=1 \

define Build/Configure
	touch $(PKG_BUILD_DIR)/*
	touch $(PKG_BUILD_DIR)/*/*
	$(SED) 's,svnversion -n .,echo $(PKG_REV),g' $(PKG_BUILD_DIR)/config.sh
	$(call Build/Configure/Default)
endef

define Build/InstallDev
	true
endef

define Package/oscam/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/oscam $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/oscam
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/share/doc/oscam/example/* $(1)/opt/etc/oscam
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S59oscam $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/var/log/oscam/cw
endef

$(eval $(call BuildPackage,oscam))
