# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025-2026 Entware

# as deps (remind)

include $(TOPDIR)/rules.mk

PKG_NAME:=perl-json-maybexs
PKG_VERSION:=1.004008
PKG_RELEASE:=1

PKG_SOURCE:=JSON-MaybeXS-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://cpan.metacpan.org/authors/id/E/ET/ETHER
PKG_HASH:=cd3937afa78831f80a2ad5abab6c51b9e82fca4c31e5856ea208d598db5dc867

PKG_BUILD_DIR:=$(BUILD_DIR)/perl/JSON-MaybeXS-$(PKG_VERSION)

PKG_LICENSE:=Artistic-1.0-Perl GPL-1.0-or-later
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=Entware team, https://entware.net

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/perl/perlmod.mk

define Package/perl-json-maybexs
  SUBMENU:=Perl
  SECTION:=lang
  CATEGORY:=Languages
  TITLE:=JSON-MaybeXS
  URL:=https://metacpan.org/dist/JSON-MaybeXS
  DEPENDS:=+perl +perlbase-encode +perlbase-experimental +perlbase-if
  DEPENDS+=+perlbase-json-pp +perlbase-storable
endef

define Build/Configure
	$(call perlmod/Configure,,)
endef

define Build/Compile
	$(call perlmod/Compile,,)
endef

define Package/perl-json-maybexs/install
	$(call perlmod/Install,$(1),JSON)
endef

$(eval $(call BuildPackage,perl-json-maybexs))
