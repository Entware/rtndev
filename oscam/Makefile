#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=oscam
PKG_REV:=11546
PKG_VERSION:=1.20-r$(PKG_REV)
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=svn
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_SUBDIR:=oscam-$(PKG_VERSION)
PKG_SOURCE_URL:=http://www.streamboard.tv/svn/oscam/trunk
PKG_SOURCE:=$(PKG_SOURCE_SUBDIR).tar.gz

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
 good MpCS version 0.9d
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
