# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/555

include $(TOPDIR)/rules.mk

PKG_NAME:=far2l
PKG_VERSION:=2.6.5
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_DATE:=2025-03-30
PKG_SOURCE_VERSION:=a071317d3b659b7da5ca1e924b3b034b0123bf32
PKG_SOURCE_URL:=https://github.com/elfmz/far2l
PKG_MIRROR_HASH:=46ec415c9cd9370825b1b2e12475be8abcba24532529424fb654a94d6a36b8a6

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
  DEPENDS:=+libarchive +libneon +libopenssl +libssh +libstdcpp +libxml2 +libnfs +libgnutls
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
