# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025-2026 Entware

# https://github.com/Entware/Entware/issues/555

include $(TOPDIR)/rules.mk

PKG_NAME:=far2l
PKG_VERSION:=2.9.1
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_DATE:=2026-10-07
PKG_SOURCE_VERSION:=3591802e656cdc0c835882651a7460732dd471f4
PKG_SOURCE_URL:=https://github.com/elfmz/far2l
PKG_MIRROR_HASH:=248ff825a65fce6cf821dddcedb05a080711dc39463415bbca25d4a9c4c14328

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-2.0-only
PKG_LICENSE_FILES:=LICENSE.txt

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/far2l
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=FAR Manager v2
  URL:=https://github.com/elfmz/far2l
  DEPENDS:=+libarchive +libneon +libopenssl +libssh +libstdcpp +libxml2 +libnfs +libgnutls +libusb-1.0
endef

define Package/far2l/description
  Linux port of FAR v2.
endef

CMAKE_OPTIONS += \
	-DCMAKE_DISABLE_FIND_PACKAGE_Git=ON \
	-DGIT_DATE=$(PKG_SOURCE_DATE) \
	-DGIT_HASH=$(call version_abbrev,$(PKG_SOURCE_VERSION)) \
	\
	-DPYTHON=no \
	-DUSEUCD=no \
	-DUSEWX=no

define Package/far2l/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/far2l $(1)/opt/bin
	$(LN) far2l $(1)/opt/bin/far2ledit
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/far2l $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/far2l $(1)/opt/share
endef

$(eval $(call BuildPackage,far2l))
