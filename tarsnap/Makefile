# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/1031

include $(TOPDIR)/rules.mk

PKG_NAME:=tarsnap
PKG_VERSION:=1.0.41
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/Tarsnap/tarsnap/tar.gz/refs/tags/$(PKG_VERSION)?
PKG_HASH:=4a72faaeba3305aa178f0efef36d4f44aaaf604596b96bbeb6bb48fc3670bc81

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=custom
PKG_LICENSE_FILES:=COPYING

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

PKG_BUILD_DEPENDS:=e2fsprogs

include $(INCLUDE_DIR)/package.mk

define Package/tarsnap
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Backup
  TITLE:=Command-line client
  URL:=https://www.tarsnap.com
  DEPENDS:=+libacl +libattr +libbz2 +libopenssl +liblzma +zlib
endef

define Package/tarsnap/description
  Tarsnap is a secure, efficient online backup service:
  "Online backups for the truly paranoid".
endef

define Package/tarsnap/conffiles
/opt/etc/tarsnap.conf
endef

define Package/tarsnap/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tarsnap $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tarsnap-keygen $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tarsnap-keymgmt $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tarsnap-keyregen $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tarsnap-recrypt $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/tarsnap.conf.sample \
		$(1)/opt/etc/tarsnap.conf
endef

$(eval $(call BuildPackage,tarsnap))
