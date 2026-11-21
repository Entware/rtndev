# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=plocate
PKG_VERSION:=1.1.25
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://plocate.sesse.net/download/
PKG_HASH:=68c1d5fbb11864403ae39c1a5937f13afd80b03e68041368831ef58cb613578e

PKG_LICENSE:=GPL-2.0-only
PKG_LICENSE_FILES:=COPYING

PKG_UNPACK=$(HOST_TAR) -xzf $(DL_DIR)/$(PKG_SOURCE) -C $(PKG_BUILD_DIR)
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/meson.mk

define Package/plocate
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=Fast file name search with a prebuilt index
	URL:=https://plocate.sesse.net/
	DEPENDS:=+libstdcpp +libzstd +libpthread +libatomic
endef

define Package/plocate/description
 Plocate is a locate(1) based on posting lists, completely replacing mlocate
 with a much faster (and smaller) index. It is suitable as a default
 locate on your system.
endef

MESON_ARGS += \
	--sharedstatedir=/opt/var/lib \
	-Dinstall_systemd=false \
	-Dlocategroup=root \
	-Dupdatedb_progname=updatedb-plocate

define Package/plocate/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/sbin $(1)/opt/var/lib/plocate
	$(INSTALL_BIN) $(MESON_BUILD_DIR)/plocate $(1)/opt/bin/
	$(INSTALL_BIN) $(MESON_BUILD_DIR)/plocate-build $(MESON_BUILD_DIR)/updatedb-plocate $(1)/opt/sbin/
endef

$(eval $(call BuildPackage,plocate))
